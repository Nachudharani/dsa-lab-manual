#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; }; struct Node *head = NULL;
void insertAtEnd(int value) {
    struct Node *node = malloc(sizeof *node); if (!node) { printf("Memory allocation failed.\n"); return; }
    node->data = value; node->next = NULL;
    if (!head) { head = node; return; } struct Node *temp = head; while (temp->next) temp = temp->next; temp->next = node;
}
void insertAtBeginning(int value) {
    struct Node *node = malloc(sizeof *node); if (!node) { printf("Memory allocation failed.\n"); return; }
    node->data = value; node->next = head; head = node;
}
void deleteValue(int value) {
    struct Node *temp = head, *prev = NULL;
    while (temp && temp->data != value) { prev = temp; temp = temp->next; }
    if (!temp) { printf("Value %d not found.\n", value); return; }
    if (!prev) head = temp->next; else prev->next = temp->next;
    free(temp); printf("Deleted %d.\n", value);
}
void traverse(void) {
    if (!head) { printf("List is empty.\n"); return; }
    printf("List: "); for (struct Node *t = head; t; t = t->next) printf("%d -> ", t->data); printf("NULL\n");
}
void cleanup(void) { while (head) { struct Node *t = head; head = head->next; free(t); } }
int main(void) {
    int choice, value;
    do {
        printf("\n1. Insert at End\n2. Insert at Beginning\n3. Delete\n4. Traverse\n5. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { cleanup(); return 1; }
        switch (choice) { case 1: printf("Enter value: "); if (scanf("%d", &value) != 1) { cleanup(); return 1; } insertAtEnd(value); break;
        case 2: printf("Enter value: "); if (scanf("%d", &value) != 1) { cleanup(); return 1; } insertAtBeginning(value); break;
        case 3: printf("Enter value to delete: "); if (scanf("%d", &value) != 1) { cleanup(); return 1; } deleteValue(value); break;
        case 4: traverse(); break; case 5: printf("Exiting...\n"); break; default: printf("Invalid choice.\n"); }
    } while (choice != 5); cleanup(); return 0;
}
