#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to calculate the height of a binary tree
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

// Function to check if a binary tree is balanced
bool isBalanced(TreeNode* root) {
    // Base case: An empty tree is balanced
    if (root == NULL) {
        return true;
    }

    // Calculate the heights of the left and right subtrees
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    // Check if the heights of the left and right subtrees differ by at most 1
    // and both the left and right subtrees are themselves balanced
    if (abs(leftHeight - rightHeight) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right)) {
        return true;
    }

    // If any of the conditions fail, the tree is not balanced
    return false;
}

int main() {
    // Constructing a balanced binary tree
    TreeNode* root_balanced = createNode(1);
    root_balanced->left = createNode(2);
    root_balanced->right = createNode(3);
    root_balanced->left->left = createNode(4);
    root_balanced->left->right = createNode(5);
    root_balanced->right->left = createNode(6);
    root_balanced->right->right = createNode(7);

    // Check if the balanced tree is indeed balanced
    if (isBalanced(root_balanced)) {
        printf("The binary tree is balanced.\n");
    } else {
        printf("The binary tree is not balanced.\n");
    }

    // Constructing an unbalanced binary tree
    TreeNode* root_unbalanced = createNode(1);
    root_unbalanced->left = createNode(2);
    root_unbalanced->left->left = createNode(3);

    // Check if the unbalanced tree is indeed balanced
    if (isBalanced(root_unbalanced)) {
        printf("The binary tree is balanced.\n");
    } else {
        printf("The binary tree is not balanced.\n");
    }

    // Free the memory allocated to the trees
    // (Assuming you have implemented a function to free the tree)
    // freeTree(root_balanced);
    // freeTree(root_unbalanced);

    return 0;
}
