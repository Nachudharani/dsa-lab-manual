#include <stdio.h>
#define MAX 100
struct Element { int data, priority; } pqueue[MAX]; int n = 0;
void insert(int data, int priority) {
    if (n == MAX) { printf("Priority queue is full.\n"); return; }
    pqueue[n++] = (struct Element){data, priority}; printf("Inserted %d with priority %d.\n", data, priority);
}
void deleteHighestPriority(void) {
    if (n == 0) { printf("Priority queue is empty.\n"); return; }
    int idx = 0; for (int i = 1; i < n; i++) if (pqueue[i].priority < pqueue[idx].priority) idx = i;
    printf("Removed %d (priority %d).\n", pqueue[idx].data, pqueue[idx].priority);
    for (int i = idx; i < n - 1; i++) pqueue[i] = pqueue[i + 1];
    n--;
}
void display(void) {
    if (n == 0) { printf("Priority queue is empty.\n"); return; }
    printf("Data\tPriority\n"); for (int i = 0; i < n; i++) printf("%d\t%d\n", pqueue[i].data, pqueue[i].priority);
}
int main(void) {
    int choice, data, priority;
    do {
        printf("\n1. Insert\n2. Delete Highest Priority\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) { case 1: printf("Enter data and priority: "); if (scanf("%d %d", &data, &priority) != 2) return 1; insert(data, priority); break;
        case 2: deleteHighestPriority(); break; case 3: display(); break; case 4: printf("Exiting...\n"); break; default: printf("Invalid choice.\n"); }
    } while (choice != 4); return 0;
}
