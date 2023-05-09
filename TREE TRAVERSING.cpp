#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int value;
    struct Node* left;
    struct Node* right;
};
struct Node* create_node(int value)
 {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void insert_node(struct Node** root, int value)
 {
    if (*root == NULL)
	 {
        *root = create_node(value);
    } else if (value < (*root)->value)
	 {
        insert_node(&((*root)->left), value);
    } else {
        insert_node(&((*root)->right), value);
    }
}
void preorder_traversal(struct Node* root) 
{
    if (root != NULL) {
        printf("%d ", root->value);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(struct Node* root)
 {
    if (root != NULL)
	 {
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(struct Node* root)
 {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->value);
    }
}
int main()
 {
    struct Node* root = NULL;
    int value;
    char c;

    printf("Enter a list of integers to be inserted into the tree: ");
    do {
        scanf("%d", &value);
        insert_node(&root, value);
        c = getchar(); 
    } while (c != '\n'); 

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}
