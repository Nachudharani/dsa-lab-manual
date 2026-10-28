#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX]; int top = -1;
int precedence(char c) { if (c == '^') return 3; if (c == '*' || c == '/') return 2; if (c == '+' || c == '-') return 1; return 0; }
int rightAssociative(char c) { return c == '^'; }
int main(void) {
    char infix[MAX], postfix[MAX]; int j = 0, valid = 1;
    printf("Enter infix expression: ");
    if (!fgets(infix, sizeof infix, stdin)) return 1;
    infix[strcspn(infix, "\n")] = '\0';
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isspace((unsigned char)c)) continue;
        if (isalnum((unsigned char)c)) postfix[j++] = c;
        else if (c == '(') { if (top == MAX - 1) { valid = 0; break; } stack[++top] = c; }
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') postfix[j++] = stack[top--];
            if (top < 0) { valid = 0; break; } top--;
        } else if (precedence(c)) {
            while (top >= 0 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c) && !rightAssociative(c)))) postfix[j++] = stack[top--];
            if (top == MAX - 1) { valid = 0; break; } stack[++top] = c;
        } else { valid = 0; break; }
        if (j >= MAX - 1) { valid = 0; break; }
    }
    while (valid && top >= 0) { if (stack[top] == '(') { valid = 0; break; } postfix[j++] = stack[top--]; }
    postfix[j] = '\0';
    if (!valid) { printf("Invalid expression.\n"); return 1; }
    printf("Postfix expression: %s\n", postfix); return 0;
}
