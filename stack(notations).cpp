#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
typedef struct Stack {
    int items[MAX];
    int top;
} Stack;
void createStack(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, int item) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}
int evaluatePostfix(char* expression) {
    Stack s;
    createStack(&s);
    char *token = expression;
    while (*token) {
        if (isdigit(*token)) {
            push(&s, *token - '0');
        } else {
            int val1 = pop(&s);
            int val2 = pop(&s);
            switch (*token) {
                case '+': push(&s, val2 + val1); break;
                case '-': push(&s, val2 - val1); break;
                case '*': push(&s, val2 * val1); break;
                case '/': 
                    if (val1 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(&s, val2 / val1); break;
            }
        }
        token++;
    }
    return pop(&s);
}
int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);
    return 0;
}
