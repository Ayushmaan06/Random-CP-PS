#include <stdio.h>
#include <stdlib.h>

// Define TreeNode structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the height (depth) of a binary tree
int treeHeight(TreeNode* root) {
    if (root == NULL) {
        return 0; // Height of an empty tree is 0
    } else {
        // Recursively calculate the height of the left and right subtrees
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        
        // Return the maximum of the heights of the left and right subtrees, plus 1 for the current node
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

int main() {
    // Constructing the binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Calculate the height of the binary tree
    int height = treeHeight(root);
    printf("Height of the binary tree: %d\n", height);

    // Free the memory allocated to the tree
    // (Assuming you have implemented a function to free the tree)
    // freeTree(root);

    return 0;
}
