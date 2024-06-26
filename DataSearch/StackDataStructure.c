#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 100


typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;


void initialize(Stack* stack) {
    stack->top = -1;
}


static int isEmpty(Stack* stack) {
    return stack->top == -1;
}


static int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}


void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = value;
}


int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->data[stack->top--];
}


int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return stack->data[stack->top];
}

int testStackDataStructure() {
    Stack stack;
    initialize(&stack);

    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    
    printf("Top element: %d\n", top(&stack));

    
    printf("Popped element: %d\n", pop(&stack));

    
    printf("Top element after pop: %d\n", top(&stack));

    return 0;
}