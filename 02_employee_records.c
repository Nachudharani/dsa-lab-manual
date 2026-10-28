#include <stdio.h>
#include <stdlib.h>

struct Employee { int id; char name[50]; char designation[30]; float salary; };

int main(void) {
    int n, searchId, found = 0;
    printf("Enter number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 1000) { printf("Invalid number of employees.\n"); return 1; }
    struct Employee *emp = malloc((size_t)n * sizeof *emp);
    if (emp == NULL) { printf("Memory allocation failed.\n"); return 1; }
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\nID: ", i + 1);
        if (scanf("%d", &emp[i].id) != 1) { free(emp); return 1; }
        printf("Name: ");
        if (scanf("%49s", emp[i].name) != 1) { free(emp); return 1; }
        printf("Designation: ");
        if (scanf("%29s", emp[i].designation) != 1) { free(emp); return 1; }
        printf("Salary: ");
        if (scanf("%f", &emp[i].salary) != 1) { free(emp); return 1; }
    }
    printf("\n%-6s %-15s %-15s %-10s\n", "ID", "Name", "Designation", "Salary");
    for (int i = 0; i < n; i++) printf("%-6d %-15s %-15s %-10.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
    printf("\nEnter employee ID to search: ");
    if (scanf("%d", &searchId) != 1) { free(emp); return 1; }
    for (int i = 0; i < n; i++) if (emp[i].id == searchId) {
        printf("Found: %d %s %s %.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary); found = 1; break;
    }
    if (!found) printf("Employee not found.\n");
    free(emp);
    return 0;
}
