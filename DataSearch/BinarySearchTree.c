#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp) {
        temp->data = key;
        temp->left = temp->right = NULL;
    }
    return temp;
}

static struct Node* insert(struct Node* root, int key) {

    if (root == NULL) return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

static struct Node* search(struct Node* root, int key) {

    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

static struct Node* deleteNode(struct Node* root, int key) {

    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }


        struct Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int testBinarySearchTree() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    int key_to_search = 50;
    struct Node* found_node = search(root, key_to_search);
    if (found_node != NULL)
        printf("Key %d found in the BST\n", key_to_search);
    else
        printf("Key %d not found in the BST\n", key_to_search);

    int key_to_delete = 20;
    root = deleteNode(root, key_to_delete);
    printf("Inorder traversal after deleting %d: ", key_to_delete);
    inorder(root);
    printf("\n");

    return 0;
}
