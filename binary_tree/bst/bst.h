#ifndef BST_BST_H
#define BST_BST_H

#endif //BST_BST_H

#include <iostream>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

typedef struct bst {
    Node *root;
    int size;
}BST;


// Create
BST createBST();

// Insert
int insertBST(BST tree, int data);

// Delete
int removeItem(BST tree, int data);

// Print (In order)
void inOrderPrint(BST tree);

// Free
int destroyBST(BST tree);

// Get Max
int getBSTMax(BST tree);

// Get Min
int getBSTMin(BST tree);

// Get Size
int getBSTSize(BST tree);

/* Helpers */

// Recursive helper tree insert
Node *treeInsert(Node *root, int data, int *ec);
// Recursive helper for deleting a node
Node *deleteNode(Node *root, int data);
Node * traversal(Node *root);