#include "bst.h"

// Create
BST createBST(){
    BST tree;
    tree.root = new(Node);

    // Set up dummy node
    tree.root->left = nullptr;
    tree.root->right = nullptr;

    // Default size
    tree.size = 0;

    return tree;
}

// Insert
int insertBST(BST tree, int data){
    int errorCode = 0;

    //Check for empty tree
    if(tree.root->right == nullptr){
        Node *head = new(Node);
        head->data = data;
        head->left = nullptr;
        head->right = nullptr;
        tree.root->right = head;

        return errorCode;
    }

    // If the tree is not empty
    Node *root = tree.root->right;
    // Error code pointer
    int *ec = &errorCode;

    // Insert left if <= to data in root
    if(data <= root->data){
        root->left = treeInsert(root->left, data, ec);
    }
    // Insert right if > data in root
    else{
        root->right = treeInsert(root->right, data, ec);
    }

    if(errorCode == 0){
        tree.size++;
    }
    return errorCode;
}

// Recursive helper tree insert
Node *treeInsert(Node *root, int data, int *ec) {
    // Base case when location is found
    if(root == nullptr){
        Node *newNode = new(Node);
        newNode->right = nullptr;
        newNode->left = nullptr;
        newNode->data = data;
        *ec = 0;
        return newNode;
    }
    // Insert left if <= to data in root
    if(data <= root->data){
        return treeInsert(root->left, data, ec);
    }
    // Insert right if > data in root
    else{
        return treeInsert(root->right, data, ec);
    }
}

// Delete
// 0 if deleted
// -1 if not found
int removeItem(BST tree, int data){
    tree.root->right = deleteNode(nullptr, 0);
}

Node *deleteNode(Node *root, int data) {
    // Base case
    if(root == nullptr){
        return root;
    }

    // Traverse left to find key
    if(root->data < data){
        root->left = deleteNode(root->left, data);
        return root;
    }
    // Traverse right to find key
    else{
        if(root->data > data){
            root->right = deleteNode(root->right, data);
            return root;
        }
    }

    // Code for when the node is found
    // Node with one or no children
    if(root->data == data){
        if(root->left == nullptr){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node *parent = root;
        Node *replacement = root->right;
        while(replacement->left != nullptr){
            parent = replacement;
            replacement = replacement->left;
        }

        // Copy replacement content to parent node
        root->data = replacement->data;

        // Delete the replacement node
        if(parent-> left == replacement){
            parent->left = replacement->right;
        }
        else{
            parent->right = replacement->right;
        }
        delete replacement;
        return root;
    }
    return root;
}

// Print (In order)
void inOrderPrint(BST tree){
    traversal(tree.root);
}

Node * traversal(Node *root){
    if(root == nullptr){
        return root;
    }
    traversal(root->left);
    std::cout << root->data << std::endl;
    traversal(root->right);
    std::cout << root->data << std::endl;
}

// Free
int destroyBST(BST tree);

// Get Max value in BST
int getBSTMax(BST tree){
    Node *p = tree.root;
    while(p->right != nullptr){
        p = p->right;
    }
    return p->data;
}

// Get Min
int getBSTMin(BST tree){
    Node *p = tree.root;
    while(p->left != nullptr){
        p = p->left;
    }
    return p->data;
}

// Get Size
int getBSTSize(BST tree){
    return tree.size;
}