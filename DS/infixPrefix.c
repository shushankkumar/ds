
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; // Return null character if stack is empty
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    reverse(infix);
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(infix[i]);
        } else if (infix[i] == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = pop();
            }
            pop(); // Remove ')'
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(infix[i])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}