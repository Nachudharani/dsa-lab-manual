#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; }; struct Node *front = NULL, *rear = NULL;
void enqueue(int value) {
    struct Node *node = malloc(sizeof *node); if (!node) { printf("Memory allocation failed.\n"); return; }
    node->data = value;
    if (!front) { front = rear = node; node->next = node; }
    else { node->next = front; rear->next = node; rear = node; }
    printf("%d enqueued.\n", value);
}
void dequeue(void) {
    if (!front) { printf("Queue underflow\n"); return; }
    struct Node *temp = front; printf("%d dequeued.\n", temp->data);
    if (front == rear) front = rear = NULL;
    else { front = front->next; rear->next = front; }
    free(temp);
}
void display(void) {
    if (!front) { printf("Queue is empty.\n"); return; }
    struct Node *temp = front; printf("Queue elements: ");
    do { printf("%d ", temp->data); temp = temp->next; } while (temp != front); printf("\n");
}
int main(void) {
    int choice, value;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) { case 1: printf("Enter value: "); if (scanf("%d", &value) != 1) return 1; enqueue(value); break;
        case 2: dequeue(); break; case 3: display(); break; case 4: printf("Exiting...\n"); break; default: printf("Invalid choice.\n"); }
    } while (choice != 4);
    while (front) { struct Node *t = front; if (front == rear) front = rear = NULL; else { front = front->next; rear->next = front; } free(t); }
    return 0;
}
