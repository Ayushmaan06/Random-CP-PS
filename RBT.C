#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

void rotateLeft(struct Node** root, struct Node* pt) {
    struct Node* pt_right = pt->right;

    pt->right = pt_right->left;
    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;
    if (pt->parent == NULL)
        *root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void rotateRight(struct Node** root, struct Node* pt) {
    struct Node* pt_left = pt->left;

    pt->left = pt_left->right;
    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;
    if (pt->parent == NULL)
        *root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void fixViolation(struct Node** root, struct Node* pt) {
    struct Node* parent_pt = NULL;
    struct Node* grand_parent_pt = NULL;

    while ((pt != *root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            struct Node* uncle_pt = grand_parent_pt->right;

            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(root, grand_parent_pt);
                int temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }
        } else {
            struct Node* uncle_pt = grand_parent_pt->left;

            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateLeft(root, grand_parent_pt);
                int temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }
        }
    }

    (*root)->color = BLACK;
}

void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    struct Node* parent = NULL;
    struct Node* current = *root;

    while (current != NULL) {
        parent = current;
        if (newNode->data < current->data)
            current = current->left;
        else if (newNode->data > current->data)
            current = current->right;
        else
            return;
    }

    newNode->parent = parent;

    if (parent == NULL)
        *root = newNode;
    else if (newNode->data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    fixViolation(root, newNode);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int n = 1;

    while (n) {
        int data;
        printf("Enter data.\n");
        scanf("%d", &data);
        insert(&root, data);
        printf("Continue? 1/0 \n");
        scanf("%d", &n);
    }

    printf("Inorder traversal of the Red-Black Tree: ");
    inorder(root);

    return 0;
}
