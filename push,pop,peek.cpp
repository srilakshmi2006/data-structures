#include <stdio.h>
#include <stdlib.h>
#define MAX 100 
typedef struct Stack {
    int items[MAX];
    int top;
} Stack;
void createStack(Stack *s) {
    s->top = -1;
}
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
    printf("Pushed %d\n", item);
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}
int main() {
    Stack s;
    createStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Top element is %d\n", peek(&s));
    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s)); 
    return 0;
}
