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

TreeNode* search(TreeNode* root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}
TreeNode* mini(TreeNode* root) {
    TreeNode* current = root;
    while(current!=NULL && current->left!=NULL) {
        current = current->left;
    }
    return current;
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

TreeNode* deleteNode(TreeNode* root, int data){
    if(root->data > data){
        root->left = deleteNode(root->left, data);
    } else if(root->data < data){
        root->right = deleteNode(root->right, data);
    } else {
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        } else if(root->left == NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        } else {
            TreeNode* temp = mini(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        
    }
    return root;
}
// Function to insert a node into the binary tree
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
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
void mirrorTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    // Swap left and right subtrees
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively convert left and right subtrees to mirror trees
    mirrorTree(root->left);
    mirrorTree(root->right);
}
// Function to check if two trees are identical
bool areIdentical(TreeNode* root1, TreeNode* root2) {
    // Base cases: If both nodes are NULL, they are identical
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    // If one node is NULL and the other is not, they are not identical
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    // Check if data of current nodes are equal and recursively check left and right subtrees
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

// Function to print the binary tree in inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        
        preorderTraversal(root->right);
    }
}
void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
// Function to free the memory allocated to the binary tree
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    // Creating an empty tree
    TreeNode* root = NULL;

    // Inserting nodes into the tree
    root = insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 3);
    insertNode(root, 8);
    insertNode(root, 12);
    insertNode(root, 18);

    // Printing the tree in inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Freeing the memory allocated to the tree
    freeTree(root);

    return 0;
}
