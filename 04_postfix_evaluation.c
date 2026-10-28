#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100
int main(void) {
    char expr[MAX]; double stack[MAX]; int top = -1;
    printf("Enter postfix expression (single-digit operands, e.g. 23+4*): ");
    if (!fgets(expr, sizeof expr, stdin)) return 1;
    expr[strcspn(expr, "\n")] = '\0';
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i]; if (isspace((unsigned char)c)) continue;
        if (isdigit((unsigned char)c)) { if (top == MAX - 1) { printf("Stack overflow.\n"); return 1; } stack[++top] = c - '0'; }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            if (top < 1) { printf("Invalid postfix expression.\n"); return 1; }
            double op2 = stack[top--], op1 = stack[top--], result;
            switch (c) {
            case '+': result = op1 + op2; break; case '-': result = op1 - op2; break;
            case '*': result = op1 * op2; break;
            case '/': if (op2 == 0) { printf("Division by zero.\n"); return 1; } result = op1 / op2; break;
            default: result = pow(op1, op2);
            }
            stack[++top] = result;
        } else { printf("Invalid character: %c\n", c); return 1; }
    }
    if (top != 0) { printf("Invalid postfix expression.\n"); return 1; }
    printf("Result = %.2f\n", stack[top]); return 0;
}
