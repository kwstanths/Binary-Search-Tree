# - Try to find myBST
# Once done this will define
#  myBST_FOUND - System has myBST
#  myBST_INCLUDE_DIRS - The myBST include directories
#  myBST_LIBRARIES - The libraries needed to use myBST

find_path(myBST_INCLUDE_DIR
	NAMES myBST.hpp
	HINTS ${myBST_ROOT}/include
	DOC "The myBST include directory"
)

find_library(myBST_LIBRARY
	NAMES myBST
	HINTS ${myBST_ROOT}/lib
	DOC "The myBST library"
)

if(myBST_INCLUDE_DIR AND myBST_LIBRARY)
	set(myBST_FOUND 1)
endif()

# Handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE if all myBSTed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(myBST DEFAULT_MSG myBST_INCLUDE_DIR myBST_LIBRARY)

if(myBST_FOUND)
	set(myBST_LIBRARIES ${myBST_LIBRARY} )
	set(myBST_INCLUDE_DIRS ${myBST_INCLUDE_DIR} )
endif()

# Tell cmake myBSTs to ignore the "local" variables
mark_as_advanced(myBST_INCLUDE_DIR myBST_LIBRARY)
