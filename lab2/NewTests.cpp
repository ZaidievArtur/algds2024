#include "pch.h"
#include "C:\Users\User\CLionProjects\Code\HelloWorld\algds2024\lab2\Project1\RB_tree_func.c"

//Проверка на черный корень
TEST(TestCaseName, TestName1) {
	RedBlackTree* tree = initializeRedBlackTree();
	insert(tree, 10);	

	EXPECT_STREQ(printTree(tree->root, tree->nil), "10(Black) ");

	EXPECT_TRUE(true);
}

//Проверка вставки элемета
TEST(TestCaseName, TestName2) {
	RedBlackTree* tree = initializeRedBlackTree();
	insert(tree, 10);
	insert(tree, 20);

	EXPECT_STREQ(printTree(tree->root, tree->nil), "10(Black) 20(Red) ");

	EXPECT_TRUE(true);
}

//Проверка удаления элемента
TEST(TestCaseName, TestName3) {
	RedBlackTree* tree = initializeRedBlackTree();
	insert(tree, 10);
	insert(tree, 20);


	Node* nodeToDelete = tree->root->right;
	delete1(tree, nodeToDelete);

	EXPECT_STREQ(printTree(tree->root, tree->nil), "10(Black) ");

	EXPECT_TRUE(true);
}

//Проверка на пустое дерево
TEST(TestCaseName, TestName4) {
	RedBlackTree* tree = initializeRedBlackTree();

	EXPECT_STREQ(printTree(tree->root, tree->nil), "");

	EXPECT_TRUE(true);
}

//Проверка сложного дерева
TEST(TestCaseName, TestName5) {
	RedBlackTree* tree = initializeRedBlackTree();

	insert(tree, 10);
	insert(tree, 20);
	insert(tree, 20);
	insert(tree, 40);
	insert(tree, 50);
	insert(tree, 60);
	insert(tree, 70);

	Node* nodeToDelete = tree->root->right;
	delete1(tree, nodeToDelete);

	EXPECT_STREQ(printTree(tree->root, tree->nil), "10(Black) 20(Black) 20(Black) 50(Red) 60(Black) 70(Red) ");

	EXPECT_TRUE(true);
}

// Проверка значения в памяти по указателям
TEST(TestCaseName, TestName6) {
	RedBlackTree* tree = initializeRedBlackTree();
	insert(tree, 10);
	insert(tree, 20);

	Node* root = tree->root;
	Node* rightChild = root->right;

	EXPECT_EQ(root->data, 10);
	EXPECT_EQ(rightChild->data, 20);
	EXPECT_EQ(root->right, rightChild);
	EXPECT_EQ(rightChild->parent, root);

	freeTree(tree->root, tree->nil);
	free(tree->nil);
	free(tree);
}

// Проверка значения в памяти по указателям при вставке и удалении
TEST(TestCaseName, TestName7) {
	RedBlackTree* tree = initializeRedBlackTree();
	insert(tree, 10);
	insert(tree, 15);
	insert(tree, 20);

	Node* root = tree->root;
	Node* rightChild = root->right;

	EXPECT_EQ(root->data, 15);
	EXPECT_EQ(rightChild->data, 20);
	EXPECT_EQ(rightChild->parent, root);

	delete1(tree, rightChild);

	EXPECT_EQ(tree->root->right, tree->nil);

	freeTree(tree->root, tree->nil);
	free(tree->nil);
	free(tree);
}
