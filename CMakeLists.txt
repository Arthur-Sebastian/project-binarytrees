cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(21Z-EADS-TASK3-MILLER-ARTUR)

add_compile_options(-Wall -Wextra -pedantic -g)

include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

#Compile dependencies
add_subdirectory(BinarySearchTreeUnitTest)
add_subdirectory(AVLTreeUnitTest)

#BST Testing executable
add_executable(BSTUnitTesting BinarySearchTreeUnitTest/BinarySearchTreeUnitTest.cpp)
target_link_libraries(BSTUnitTesting PUBLIC bst_test)

#BST Benchmark executable
add_executable(BSTBenchmark BinarySearchTreeApp/BinarySearchTreeApp.cpp)

#AVL Testing executable
add_executable(AVLUnitTesting AVLTreeUnitTest/AVLTreeUnitTest.cpp)
target_link_libraries(AVLUnitTesting PUBLIC avl_test)

#AVL Benchmark executable
add_executable(AVLBenchmark AVLTreeApp/AVLTreeApp.cpp)

