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

// Function to find the lowest common ancestor (LCA) of two nodes
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base cases
    if (root == NULL || root == p || root == q) {
        return root;
    }
    // Recursively search left and right subtrees for LCA
    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
    // If both left and right LCA are not NULL, root is the LCA
    if (leftLCA && rightLCA) {
        return root;
    }
    // Otherwise, return non-NULL LCA (if any)
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    // Constructing a binary tree
    TreeNode* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    // Nodes whose lowest common ancestor is to be found
    TreeNode* p = root->left;
    TreeNode* q = root->right;

    // Find lowest common ancestor
    TreeNode* lca = lowestCommonAncestor(root, p, q);

    // Print the lowest common ancestor
    if (lca != NULL) {
        printf("Lowest common ancestor of %d and %d is %d\n", p->data, q->data, lca->data);
    } else {
        printf("Lowest common ancestor not found\n");
    }

    // Free the memory allocated to the tree
    // (Assuming you have implemented a function to free the tree)
    // freeTree(root);

    return 0;
}
