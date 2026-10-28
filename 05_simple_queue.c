#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void enqueue(int value) {
    if (rear == MAX - 1) { printf("Queue overflow\n"); return; }
    if (front == -1) front = 0;
    queue[++rear] = value; printf("%d enqueued.\n", value);
}
void dequeue(void) {
    if (front == -1) { printf("Queue underflow\n"); return; }
    printf("%d dequeued.\n", queue[front++]);
    if (front > rear) front = rear = -1;
}
void display(void) {
    if (front == -1) { printf("Queue is empty.\n"); return; }
    printf("Queue elements: "); for (int i = front; i <= rear; i++) printf("%d ", queue[i]); printf("\n");
}
int main(void) {
    int choice, value;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) { case 1: printf("Enter value to enqueue: "); if (scanf("%d", &value) != 1) return 1; enqueue(value); break;
        case 2: dequeue(); break; case 3: display(); break; case 4: printf("Exiting...\n"); break; default: printf("Invalid choice.\n"); }
    } while (choice != 4); return 0;
}
