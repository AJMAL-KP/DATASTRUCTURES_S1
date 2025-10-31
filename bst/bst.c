#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;






void preOrder(struct node *root) {
    if (root == NULL) return;
    printf("%d -> ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d -> ", root->data);
    inOrder(root->right);
}

void postOrder(struct node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d -> ", root->data);
}

int display() {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return 1;
    }

    printf("Preorder: ");
    preOrder(root);
    printf("NULL\nInorder: ");
    inOrder(root);
    printf("NULL\nPostorder: ");
    postOrder(root);
    printf("NULL\n");

    return 0;
}

struct node *insert(struct node *root, struct node *newnode) {
    if (root == NULL) {
        root = newnode;
    } else if (root->data > newnode->data) {
        root->left = insert(root->left, newnode);
    } else if (root->data < newnode->data) {
        root->right = insert(root->right, newnode);
    }
    return root;
}


void insertion() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter Node to Insert: ");
    scanf("%d", &newnode->data);

    newnode->left = newnode->right = NULL;

    root = insert(root, newnode);
    display();
}

struct node *min(struct node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *delete(struct node *root, int value) {
    if (root == NULL) {
        printf("Not found\n");
        return root;
    }

    if (value < root->data)
        root->left = delete(root->left, value);
    else if (value > root->data)
        root->right = delete(root->right, value);
    else {
        struct node *temp;
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        root->data = min(root->right)->data;
        root->right = delete(root->right, root->data);
    }
    return root;
}


void deletion() {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }

    int value;
    printf("Enter node value to delete: ");
    scanf("%d", &value);

    root = delete(root, value);
    display();
}


struct node *search(struct node *root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void searching() {
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);

    struct node *result = search(root, value);
    if (result != NULL)
        printf("Value %d found in the tree.\n", value);
    else
        printf("Value %d not found in the tree.\n", value);
}

int main() {
    while (1) {
        int choice;
        printf("\n ====== Binary Operations ===== \n 0 to display, \n 1 to insert, \n 2 to delete, \n 3 to search, \n 5 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                display();
                break;
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                searching();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}
