#include <string>
#include <gtest/gtest.h>
#include "../BinarySearchTreeLib/BinarySearchTree.hpp"

TEST(BinaryTree, ConstructEmpty)
{
	BinarySearchTree<int, int> tree;
	std::string expected = "";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertToEmpty)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	std::string expected = "([10,100],,)";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe2LevelOnTheLeftThereIsNoRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(5, 50);
	std::string expected = "([10,100],([5,50],,),)";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe2LevelOnTheRightThereIsNoLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(20, 200);
	std::string expected = "([10,100],,([20,200],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe2LevelOnTheLeftThereIsRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(20, 200);
	tree.insert(5, 50);
	std::string expected = "([10,100],([5,50],,),([20,200],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe2LevelOnTheRightThereIsLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(5, 50);
	tree.insert(20, 200);
	std::string expected = "([10,100],([5,50],,),([20,200],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe3LevelLeftLeftThereIsNoRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(10, 100);
	std::string expected = "([50,500],([20,200],([10,100],,),),([80,800],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe3LevelLeftLeftThereIsRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(30, 300);
	tree.insert(10, 100);
	std::string expected = "([50,500],([20,200],([10,100],,),([30,300],,)),([80,800],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe3LevelLeftRightThereIsNoLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(30, 300);
	std::string expected = "([50,500],([20,200],,([30,300],,)),([80,800],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe3LevelLeftRightThereIsLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(10, 100);
	tree.insert(30, 300);
	std::string expected = "([50,500],([20,200],([10,100],,),([30,300],,)),([80,800],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe3LevelRightLeftThereIsNoRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(70, 700);
	std::string expected = "([50,500],([20,200],,),([80,800],([70,700],,),))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe3LevelRightLeftThereIsRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(90, 900);
	tree.insert(70, 700);
	std::string expected = "([50,500],([20,200],,),([80,800],([70,700],,),([90,900],,)))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe3LevelRightRightThereIsNoLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(90, 900);
	std::string expected = "([50,500],([20,200],,),([80,800],,([90,900],,)))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertOnThe3LevelRightRightThereIsLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(70, 700);
	tree.insert(90, 900);
	std::string expected = "([50,500],([20,200],,),([80,800],([70,700],,),([90,900],,)))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, insertExisting)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(70, 700);
	tree.insert(90, 900);
	tree.insert(50, 501);
	tree.insert(20, 201);
	tree.insert(80, 801);
	tree.insert(70, 701);
	tree.insert(90, 901);
	std::string expected = "([50,501],([20,201],,),([80,801],([70,701],,),([90,901],,)))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, removeFromEmpty)
{
	BinarySearchTree<int, int> tree;
	tree.remove(10);
	std::string expected = "";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, removeRoot)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.remove(50);
	std::string expected = "";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, removeNotExisting)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(70, 700);
	tree.insert(90, 900);
	tree.insert(50, 501);
	tree.insert(20, 201);
	tree.insert(80, 801);
	tree.insert(70, 701);
	tree.insert(90, 901);
	tree.remove(25);
	std::string expected = "([50,501],([20,201],,),([80,801],([70,701],,),([90,901],,)))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, removeNodeWithoutChildren)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.remove(20);
	std::string expected = "([50,500],,([80,800],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, removeNodeWithoutLeftChild)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(30, 300);
	tree.remove(20);
	std::string expected = "([50,500],([30,300],,),([80,800],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, removeNodeWithoutRightChild)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(10, 100);
	tree.remove(20);
	std::string expected = "([50,500],([10,100],,),([80,800],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, removeNodeWithChildren)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(10, 100);
	tree.insert(30, 300);
	tree.insert(15, 150);
	tree.insert(12, 120);
	tree.remove(20);
	std::string expected = "([50,500],([15,150],([10,100],,([12,120],,)),([30,300],,)),([80,800],,))";
	ASSERT_EQ(expected, tree.toString());
}
TEST(BinaryTree, findInEmpty)
{
	BinarySearchTree<int, int> tree;
	ASSERT_EQ(tree.find(10), nullptr);
}
TEST(BinaryTree, findNotExisted)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(5, 50);
	tree.insert(20, 200);
	ASSERT_EQ(tree.find(2), nullptr);
	ASSERT_EQ(tree.find(7), nullptr);
	ASSERT_EQ(tree.find(12), nullptr);
	ASSERT_EQ(tree.find(24), nullptr);
}
TEST(BinaryTree, findOnThe1LevelNoChildren)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	ASSERT_EQ(100, *tree.find(10));
	tree.insert(5, 50);
	ASSERT_EQ(100, *tree.find(10));
	tree.insert(20, 200);
	ASSERT_EQ(100, *tree.find(10));
}
TEST(BinaryTree, findOnThe1LevelIsLeftChild)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(5, 50);
	ASSERT_EQ(100, *tree.find(10));
}
TEST(BinaryTree, findOnThe1LevelIsRightChild)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(20, 200);
	ASSERT_EQ(100, *tree.find(10));
}
TEST(BinaryTree, findOnThe1LevelAreChildren)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(5, 50);
	tree.insert(20, 200);
	ASSERT_EQ(100, *tree.find(10));
}
TEST(BinaryTree, findOnThe2LevelOnTheLeftThereIsNoRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(5, 50);
	ASSERT_EQ(50, *tree.find(5));
}
TEST(BinaryTree, findOnThe2LevelOnTheRightThereIsNoLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(20, 200);
	ASSERT_EQ(200, *tree.find(20));
}
TEST(BinaryTree, findOnThe2LevelOnTheLeftThereIsRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(20, 200);
	tree.insert(5, 50);
	ASSERT_EQ(50, *tree.find(5));
}
TEST(BinaryTree, findOnThe2LevelOnTheRightThereIsLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(10, 100);
	tree.insert(5, 50);
	tree.insert(20, 200);
	ASSERT_EQ(200, *tree.find(20));
}
TEST(BinaryTree, findOnThe3LevelLeftLeftThereIsNoRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(10, 100);
	ASSERT_EQ(100, *tree.find(10));
}
TEST(BinaryTree, findOnThe3LevelLeftLeftThereIsRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(30, 300);
	tree.insert(10, 100);
	ASSERT_EQ(100, *tree.find(10));
}
TEST(BinaryTree, findOnThe3LevelLeftRightThereIsNoLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(30, 300);
	ASSERT_EQ(300, *tree.find(30));
}
TEST(BinaryTree, findOnThe3LevelLeftRightThereIsLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(10, 100);
	tree.insert(30, 300);
	ASSERT_EQ(300, *tree.find(30));
}
TEST(BinaryTree, findOnThe3LevelRightLeftThereIsNoRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(70, 700);
	ASSERT_EQ(700, *tree.find(70));
}
TEST(BinaryTree, findOnThe3LevelRightLeftThereIsRight)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(90, 900);
	tree.insert(70, 700);
	ASSERT_EQ(700, *tree.find(70));
}
TEST(BinaryTree, findOnThe3LevelRightRightThereIsNoLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(90, 900);
	ASSERT_EQ(900, *tree.find(90));
}
TEST(BinaryTree, findOnThe3LevelRightRightThereIsLeft)
{
	BinarySearchTree<int, int> tree;
	tree.insert(50, 500);
	tree.insert(20, 200);
	tree.insert(80, 800);
	tree.insert(70, 700);
	tree.insert(90, 900);
	ASSERT_EQ(900, *tree.find(90));
}
TEST(BinaryTree, print0)
{
	BinarySearchTree<int, int> tree;
	std::ostringstream stream;
	tree.print(stream);
	auto s = stream.str();
	std::string s1 = "";
	ASSERT_EQ(s1, s);
}
TEST(BinaryTree, print1)
{
	BinarySearchTree<int, int> tree;
	tree.insert(1, 1);
	std::ostringstream stream;
	tree.print(stream);
	auto s = stream.str();
	std::string s1 = "[1, 1]\n";
	ASSERT_EQ(s1, s);
}
TEST(BinaryTree, print3)
{
	BinarySearchTree<int, int> tree;
	tree.insert(2, 2);
	tree.insert(1, 1);
	tree.insert(3, 3);
	std::ostringstream stream;
	tree.print(stream);
	auto s = stream.str();
	std::string s1 = "[2, 2]\n    L: [1, 1]\n    R: [3, 3]\n";
	ASSERT_EQ(s1, s);
}
TEST(BinaryTree, print7)
{
	BinarySearchTree<int, int> tree;
	tree.insert(4, 4);
	tree.insert(2, 2);
	tree.insert(1, 1);
	tree.insert(3, 3);
	tree.insert(6, 6);
	tree.insert(5, 5);
	tree.insert(7, 7);

	std::ostringstream stream;
	tree.print(stream);
	auto s = stream.str();
	std::string s1 = "[4, 4]\n    L: [2, 2]\n        L: [1, 1]\n        R: [3, 3]\n    R: [6, 6]\n        L: [5, 5]\n        R: [7, 7]\n";
	ASSERT_EQ(s1, s);
}

int main (int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
