#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

// Define TreeNode structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Array to store inorder traversal data
int inorderArray[MAX_NODES];
int index = 0;

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

// Function to perform inorder traversal and store data in array
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        inorderArray[index++] = root->data;
        inorderTraversal(root->right);
    }
}

// Function to check if the array is sorted
bool isSorted(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to check if the binary tree is a binary search tree
bool isBST(TreeNode* root) {
    // Perform inorder traversal and store data in array
    inorderTraversal(root);

    // Check if the array is sorted
    return isSorted(inorderArray, index);
}

int main() {
    // Constructing the binary tree
    TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(0);

    // Check if the tree is a binary search tree
    if (isBST(root)) {
        printf("The binary tree is a binary search tree.\n");
    } else {
        printf("The binary tree is not a binary search tree.\n");
    }

    return 0;
}
