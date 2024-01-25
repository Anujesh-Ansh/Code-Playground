#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

Node *delete(Node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root=NULL;
            
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else {
            Node *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node *root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert element into the tree");
        printf("\n2. In-order traversal");
        printf("\n3. Pre-order traversal");
        printf("\n4. Post-order traversal");
        printf("\n5. Delete an element from the tree");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("\nIn-order traversal: ");
                inOrder(root);
                printf("\n");
                break;

            case 3:
                printf("\nPre-order traversal: ");
                preOrder(root);
                printf("\n");
                break;

            case 4:
                printf("\nPost-order traversal: ");
                postOrder(root);
                printf("\n");
                break;
            
            case 5:
                printf("\nEnter the element to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice\n");
                break;
        }
    }

    return 0;
}

