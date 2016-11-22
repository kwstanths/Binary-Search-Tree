#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include <algorithm>

#include "myBST.hpp"

struct teststruct{
	int garbage1;
	std::string garbage2;

	teststruct(int _garbage1, std::string _garbage2): garbage1(_garbage1), garbage2(_garbage2){ };

	bool operator!=(struct teststruct& other){
		return other.garbage1 != garbage1;
	}

	bool operator==(struct teststruct& other){
		return other.garbage1 == garbage1;
	}

	bool operator<(struct teststruct& other){
		return garbage1 < other.garbage1;
	}

	bool operator>(struct teststruct& other){
		return garbage1 > other.garbage1;
	}

};
typedef struct teststruct teststructtype;

int main(int argc, char ** argv){

	mns::bst::BinarySearchTree<int> bst1;
	mns::bst::BinarySearchTree<int> bst2(5);
	mns::bst::BinarySearchTree<std::string> bst3;
	mns::bst::BinarySearchTree<std::string> bst4("hey");
	mns::bst::BinarySearchTree<teststructtype> bst5;
	mns::bst::BinarySearchTree<teststructtype *> bst6;

	bst1.insert(15);

	bst2.insert(4);
	bst2.insert(7);

	bst3.insert("f");
	bst3.insert("c");
	bst3.insert("i");
	bst3.insert("a");
	bst3.insert("d");
	bst3.insert("j");
	bst3.insert("g");

	std::cout << "15: " << bst1.find(15) << std::endl;
	std::cout << "14: " << bst1.find(14) << std::endl;
	std::cout << "16: " << bst1.find(16) << std::endl;

	std::cout << "3: " << bst2.find(3) << std::endl;
	std::cout << "4: " << bst2.find(4) << std::endl;
	std::cout << "5: " << bst2.find(5) << std::endl;
	std::cout << "6: " << bst2.find(6) << std::endl;
	std::cout << "7: " << bst2.find(7) << std::endl;
	std::cout << "8: " << bst2.find(8) << std::endl;

	std::cout << "a: " << bst3.find("a") << std::endl;
	std::cout << "b: " << bst3.find("b") << std::endl;
	std::cout << "c: " << bst3.find("c") << std::endl;
	std::cout << "d: " << bst3.find("d") << std::endl;
	std::cout << "e: " << bst3.find("e") << std::endl;
	std::cout << "f: " << bst3.find("f") << std::endl;
	std::cout << "g: " << bst3.find("g") << std::endl;
	std::cout << "h: " << bst3.find("h") << std::endl;
	std::cout << "i: " << bst3.find("i") << std::endl;
	std::cout << "j: " << bst3.find("j") << std::endl;

	bst1.remove(15);
	std::cout << "15: " << bst1.find(15) << std::endl;
	std::cout << "14: " << bst1.find(14) << std::endl;
	std::cout << "16: " << bst1.find(16) << std::endl;
	bst1.insert(14);
	bst1.insert(22);
	bst1.insert(11);
	bst1.insert(9);
	bst1.insert(13);
	bst1.insert(16);
	bst1.insert(30);
	std::cout << "15: " << bst1.find(15) << std::endl;
	std::cout << "14: " << bst1.find(14) << std::endl;
	std::cout << "16: " << bst1.find(16) << std::endl;
	std::cout << "9: " << bst1.find(9) << std::endl;
	std::cout << "13: " << bst1.find(13) << std::endl;
	std::cout << "16: " << bst1.find(16) << std::endl;
	std::cout << "30: " << bst1.find(30) << std::endl;
	std::cout << "22: " << bst1.find(22) << std::endl;
	std::cout << "14: " << bst1.find(13) << std::endl;
	std::cout << "11: " << bst1.find(11) << std::endl;
	bst3.remove("d");
	std::cout << "d: " << bst3.find("d") << std::endl;
	bst3.insert("d");
	std::cout << "d: " << bst3.find("d") << std::endl;

	std::cout << "--" << std::endl;

	mns::bst::BinarySearchTree<int> testbst;
	testbst.insert(5);
	testbst.insert(18);
	testbst.insert(17);
	testbst.insert(21);
	testbst.insert(19);
	testbst.insert(25);
	testbst.insert(2);
	testbst.insert(-4);
	testbst.insert(3);
 	testbst.insert(26);

	std::cout << "Height: " << testbst.height() << std::endl;
	std::cout << "Min: " << testbst.min()->getValue() << std::endl;
	std::cout << "Max: " << testbst.max()->getValue() << std::endl;

	testbst.clear();
	std::cout << testbst.find(5) << std::endl;
	std::cout << testbst.find(17) << std::endl;
	std::cout << testbst.find(25) << std::endl;
	std::cout << testbst.find(3) << std::endl;
	testbst.insert(5);
	testbst.insert(17);
	testbst.insert(3);
	std::cout << testbst.find(5) << std::endl;
	std::cout << testbst.find(17) << std::endl;
	std::cout << testbst.find(25) << std::endl;
	std::cout << testbst.find(3) << std::endl;

	std::cout << "--" << std::endl;

	testbst.clear();
	testbst.insert(10);
	testbst.insert(14);
	testbst.insert(6);
	testbst.insert(16);
	testbst.insert(2);
	testbst.insert(8);
	testbst.insert(12);

	std::cout << "DEFAULT\n";
	for(typename mns::bst::BinarySearchTree<int>::iterator itr = testbst.begin(); itr!=testbst.end(); ++itr){
	 	std::cout << "" << *itr << std::endl;
	}

	std::cout << "--" << std::endl;

	std::cout << "PREORDER\n";
	for(typename mns::bst::BinarySearchTree<int>::iterator itr = testbst.begin("PREORDER"); itr!=testbst.end(); ++itr){
		std::cout << "" << *itr << std::endl;
	}

	std::cout << "--" << std::endl;

	std::cout << "INORDER\n";
	for(typename mns::bst::BinarySearchTree<int>::iterator itr = testbst.begin("INORDER"); itr!=testbst.end(); ++itr){
		std::cout << "" << *itr << std::endl;
	}

	std::cout << "--" << std::endl;

	teststructtype struct1(1, "1");
	teststructtype struct2(2, "2");
	teststructtype struct3(3, "3");
	teststructtype struct4(4, "4");
	teststructtype struct5(5, "5");
	teststructtype struct6(6, "6");
	teststructtype struct7(7, "7");
	bst5.insert(struct3);
	bst5.insert(struct4);
	bst5.insert(struct5);
	bst5.insert(struct2);
	bst5.insert(struct1);
	std::cout << bst5.find(struct5) << std::endl;
	std::cout << bst5.find(struct2) << std::endl;
	std::cout << bst5.find(struct6) << std::endl;
	std::cout << bst5.find(struct1) << std::endl;
	std::cout << bst5.find(struct7) << std::endl;

	std::cout << "POSTORDER\n";
	for(typename mns::bst::BinarySearchTree<teststructtype>::iterator itr = bst5.begin("POSTORDER"); itr!=bst5.end(); ++itr){
		std::cout << "" << (*itr).garbage1 << std::endl;
		std::cout << "" << (*itr).garbage2 << std::endl;
	}

	std::cout << "POSTORDER\n";
	for(typename mns::bst::BinarySearchTree<teststructtype>::iterator itr = bst5.begin("POSTORDER"); itr!=bst5.end(); itr+=2){
		std::cout << "" << (*itr).garbage1 << std::endl;
		std::cout << "" << (*itr).garbage2 << std::endl;
	}

	std::cout << "--" << std::endl;
	
	//Only addresses are taken into consideration

	teststructtype * struct10 = new teststructtype(10,"10");
	teststructtype * struct11 = new teststructtype(11,"11");
	teststructtype * struct12 = new teststructtype(12,"12");
	teststructtype * struct13 = new teststructtype(13,"13");
	teststructtype * struct14 = new teststructtype(14,"14");
	bst6.insert(struct12);
	bst6.insert(struct11);
	bst6.insert(struct10);
	bst6.insert(struct13);
	std::cout << bst6.find(struct13) << std::endl;
	std::cout << bst6.find(struct11) << std::endl;
	std::cout << bst6.find(struct12) << std::endl;
	std::cout << bst6.find(&struct5) << std::endl;

	std::cout << "PREORDER\n";
	for(typename mns::bst::BinarySearchTree<teststructtype*>::iterator itr = bst6.begin("PREORDER"); itr!=bst6.end(); ++itr){
		std::cout << "" << (*itr)->garbage1 << std::endl;
		std::cout << "" << (*itr)->garbage2 << std::endl;
	}


}
