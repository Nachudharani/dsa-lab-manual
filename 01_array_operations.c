#include <stdio.h>
#define MAX 100

void display(const int a[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int a[MAX], n, choice, pos, value;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > MAX) { printf("Invalid size.\n"); return 1; }
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) if (scanf("%d", &a[i]) != 1) return 1;
    do {
        printf("\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
        case 1:
            if (n == MAX) { printf("Array is full. Cannot insert.\n"); break; }
            printf("Enter position (0 to %d) and value: ", n);
            if (scanf("%d %d", &pos, &value) != 2) return 1;
            if (pos < 0 || pos > n) { printf("Invalid position.\n"); break; }
            for (int i = n; i > pos; i--) a[i] = a[i - 1];
            a[pos] = value; n++; display(a, n); break;
        case 2:
            printf("Enter position to delete (0 to %d): ", n - 1);
            if (scanf("%d", &pos) != 1) return 1;
            if (pos < 0 || pos >= n) { printf("Invalid position.\n"); break; }
            for (int i = pos; i < n - 1; i++) a[i] = a[i + 1];
            n--; display(a, n); break;
        case 3: display(a, n); break;
        case 4: printf("Exiting...\n"); break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}
