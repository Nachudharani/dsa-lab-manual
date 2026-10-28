#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *left, *right; };
struct Node *createNode(int value) { struct Node *node = malloc(sizeof *node); if (!node) { fprintf(stderr, "Memory allocation failed.\n"); exit(1); } node->data = value; node->left = node->right = NULL; return node; }
struct Node *insert(struct Node *root, int value) { if (!root) return createNode(value); if (value < root->data) root->left = insert(root->left, value); else if (value > root->data) root->right = insert(root->right, value); return root; }
void inorder(struct Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(struct Node *r) { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(struct Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }
void freeTree(struct Node *r) { if (r) { freeTree(r->left); freeTree(r->right); free(r); } }
int main(void) {
    struct Node *root = NULL; int n, value;
    printf("Enter number of nodes: "); if (scanf("%d", &n) != 1 || n < 0 || n > 10000) { printf("Invalid number of nodes.\n"); return 1; }
    printf("Enter %d values: ", n); for (int i = 0; i < n; i++) { if (scanf("%d", &value) != 1) { freeTree(root); return 1; } root = insert(root, value); }
    printf("\nIn-order traversal: "); inorder(root); printf("\nPre-order traversal: "); preorder(root); printf("\nPost-order traversal: "); postorder(root); printf("\n"); freeTree(root); return 0;
}
