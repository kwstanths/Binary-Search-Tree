#ifndef __BINARYSEARCHTREE_HPP__
#define __BINARYSEARCHTREE_HPP__

#include <iostream>
#include <queue>

namespace mns{

namespace bst {
	//TODO custom user defined function in case of type is a pointer
      template <typename T> class BinarySearchTree;

      template <typename T> class BinarySearchTree_iterator;

      template <typename T> class bst_node{
		friend class BinarySearchTree<T>;
		friend class BinarySearchTree_iterator<T>;

      private:
		T value;
		bst_node<T> * left;
		bst_node<T> * right;

            bst_node(const T& _value, bst_node<T> * _left, bst_node<T> * _right): value(_value), left(_left), right(_right){}

            ~bst_node(){
                  if (left != NULL) delete left;
                  if (right != NULL) delete right;
            }

            bool insert(T _value){

                  if (_value < value){
                        if (left == NULL) {
                              left = new bst_node<T>(_value, NULL, NULL);
                              return true;
                        }else return left->insert(_value);
                  }

                  if (_value > value) {
                        if (right == NULL){
                              right = new bst_node<T>(_value, NULL, NULL);
                              return true;
                        }else return right->insert(_value);
                  }

                  return false;
            }

            bool find(T _value){

                  if (_value < value){
                        if (left == NULL) return false;
                        return left->find(_value);
                  }

                  if (_value > value){
                        if (right == NULL) return false;
                        return right->find(_value);
                  }
            }

            bst_node<T> * remove(T _value, bst_node<T> * parent){
                  if (_value < value){
                        if (left != NULL) return left->remove(_value, this);
                        else return NULL;
                  }

                  if ( _value > value){
                        if (right != NULL) return right->remove(_value, this);
                        else return NULL;
                  }

                  if (left != NULL && right != NULL){
                        value = right->minValue();
                        return right->remove(value, this);
                  }

                  if (parent->left == this){
                        parent->left = (left != NULL) ? left : right;
                        return this;
                  }

                  if (parent->right == this){
                        parent->right = (left != NULL) ? left : right;
                        return this;
                  }
            }

            T minValue(){
                  if (left == NULL) return value;
                  else return left->minValue();
            }

            int height(){
                  int leftheight = (left == NULL) ? 0 : left->height();
                  int rightheight = (right == NULL) ? 0 : right->height();
                  return 1 + std::max(leftheight, rightheight);
            }

            bst_node<T> * min(){
                  if (left == NULL) return this;
                  return left->min();
            }

            bst_node<T> * max(){
                  if (right == NULL) return this;
                  return right->max();
            }

            void clear(){
                  if (left != NULL) left->clear();
                  if (right != NULL) right->clear();

                  delete left;
                  delete right;
                  return;
            }

	public:
            /*
                  Returns the value of the node
                  @return The value of the node
            */
		T getValue() const{
			return value;
		}

            /*
                  Returns the left child of this node
                  @return A pointer to the left child
            */
            bst_node * getLeft() const{
                  return left;
            }

            /*
                  Returns the right child of this node
                  @return A pointer to the right child
            */
            bst_node * getRight() const{
                  return right;
            }
	};

      template<typename T> class BinarySearchTree{

      private:
            bst_node<T> * root;

      public:
            typedef BinarySearchTree_iterator<T> iterator;

            /*
                  Creates a tree with the root pointing to NULL
            */
            BinarySearchTree(): root(NULL){};

            /*
                  Creates a tree with the root pointing to a starting node;
            */
            BinarySearchTree(T _value){
			std::cout << "test" << std::endl;
                  root = new bst_node<T>(_value, NULL, NULL);
            }

            ~BinarySearchTree(){
                  clear();
            }

            /*
                  Destroys the tree
            */
            void clear(){
                  if (root == NULL) return;
                  delete root;
                  root = NULL;
            }

            /*
                  Inserts a new value to the tree
                  @return True: Values is inserted, False: Value already exists
            */
            bool insert(T _value){
                  if (root == NULL){
                        root = new bst_node<T>(_value, NULL, NULL);
                        return true;
                  }
                  return root->insert(_value);
            }

            /*
                  Searches for a value
                  @return True: Value exists, False: Value does not exist
            */
            bool find(T _value) const{
                  if (root == NULL) return false;

                  return root->find(_value);
            }

            /*
                  Removes a value froma the tree
                  @return True: Value removed, False: Value does not exist
            */
            bool remove(T _value){
                  if (root == NULL) return false;

                  if (root->value == _value){
                        bst_node<T> tempRoot(0, root->left, NULL);
                        bst_node<T> * toRemoveNode = root->remove(_value, &tempRoot);
                        root = tempRoot.getLeft();
                        if (toRemoveNode != NULL){
                              delete toRemoveNode;
                              return true;
                        }else return false;
                  }

                  bst_node<T> * toRemoveNode = root->remove(_value, NULL);
                  if (toRemoveNode != NULL){
                        delete toRemoveNode;
                        return true;
                  }else return false;
            }

            /*
                  Returns the height of the tree
                  @return The height of the tree
            */
            int height() const{
                  if (root == NULL) return 0;

                  return root->height();
            }

            /*
                  Returns a pointer the min value
                  @return A pointer to the node with the min value
            */
            bst_node<T> * min() const{
                  if (root == NULL) return NULL;

                  if (root->left == NULL) return root;

                  return root->min();
            }

            /*
                  Returns a pointer to the max value
                  @return A pointer to the node with the max value
            */
            bst_node<T> * max() const{
                  if (root == NULL) return NULL;

                  if (root->right == NULL) return root;

                  return root->max();
            }

            /*
                  Returns a preorder iterator of the tree
                  @return A preorder iterator
            */
            iterator begin(){
                  return BinarySearchTree_iterator<T>(root, 1);
            }

            /*
                  Returns an iterator of the tree
                  @param type The type of the iterator. Accepted values are "PREORDER", "INORDER", "POSTORDER"
                  @return An iterator
            */
            iterator begin(const std::string& type) {
                  if (type == "PREORDER") return BinarySearchTree_iterator<T>(root, 1);
                  if (type == "INORDER") return BinarySearchTree_iterator<T>(root, 2);
                  if (type == "POSTORDER") return BinarySearchTree_iterator<T>(root, 3);

                  return BinarySearchTree_iterator<T>(root, 1);
            }

            /*
                  Returns an ending iterator
                  @return An ending iterator
            */
            iterator end(){
                  return BinarySearchTree_iterator<T>(NULL, 0);
            }

      };

      template <typename T> class BinarySearchTree_iterator : public std::iterator<std::forward_iterator_tag, T>{
		friend class BinarySearchTree<T>;
	private:
            std::queue<bst_node<T> * > * nodequeue;
            bst_node<T> * pointed;

	BinarySearchTree_iterator(bst_node<T> * _pointed, int type): pointed(_pointed){
		nodequeue = new std::queue<bst_node<T> *>();

		if (type == 1) preorder_traversal(_pointed);
		if (type == 2) inorder_traversal(_pointed);
		if (type == 3) postorder_traversal(_pointed);

		pointed = nodequeue->front();
            }

            void preorder_traversal(bst_node<T> * temproot){
                  if (temproot != NULL){
                        nodequeue->push(temproot);
                        preorder_traversal(temproot->left);
                        preorder_traversal(temproot->right);
                  }
            }

            void inorder_traversal(bst_node<T> * temproot){
                  if(temproot != NULL){
                        inorder_traversal(temproot->left);
                        nodequeue->push(temproot);
                        inorder_traversal(temproot->right);
                  }
            }

            void postorder_traversal(bst_node<T> * temproot){
                  if (temproot != NULL){
                        postorder_traversal(temproot->left);
                        postorder_traversal(temproot->right);
                        nodequeue->push(temproot);
                  }
            }

	public:
		T& operator*(){
			return pointed->value;
		}

		const BinarySearchTree_iterator<T>& operator++(){
                  nodequeue->pop();
                  pointed = nodequeue->front();
                  return *this;
		}

		const BinarySearchTree_iterator<T>& operator+=(int amount){
			int i = 0;
			while(i++ < amount){
				nodequeue->pop();
                        pointed = nodequeue->front();
			}
		}

		bool operator!=(const BinarySearchTree_iterator<T>& other) const {
			return this->pointed != other.pointed;
		}

	};

}

}

#endif
