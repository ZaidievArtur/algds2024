#pragma once

typedef struct Node {
    int data;
    int color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
    Node* nil;
} RedBlackTree;

RedBlackTree* initializeRedBlackTree();

Node* createNode(int data);

char* printTree(Node* root, Node* nil);

void leftRotate(RedBlackTree* tree, Node* x);

void rightRotate(RedBlackTree* tree, Node* x);

void insertFixup(RedBlackTree* tree, Node* z);

void insert(RedBlackTree* tree, int data);

void freeTree(Node* node, Node* nil);

void deleteFixup(RedBlackTree* tree, Node* x);

void delete1(RedBlackTree* tree, Node* z);