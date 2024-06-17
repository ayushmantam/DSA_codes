#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;
    int top;
    int size;
};

typedef struct Stack Stack;


Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack->size = size;
    stack->arr = (int*)malloc(size * sizeof(int));
    if (stack->arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int element) {
    if (stack->top < stack->size - 1) {
        stack->top++;
        stack->arr[stack->top] = element;
    } else {
        printf("Stack overflow\n");
    }
}

void pop(Stack* stack) {
    if (stack->top >= 0) {
        stack->top--;
    } else {
        printf("Stack underflow\n");
    }
}

int peek(Stack* stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top];
    } else {
        printf("Stack is Empty\n");
        return -1;
    }
}

int isEmpty(Stack* stack) {
    if (stack->top == -1) {
        return 1; // true
    } else {
        return 0; // false
    }
}

int main() {
    Stack* st = createStack(5);
    push(st, 22);
    push(st, 43);
    push(st, 44);
    printf("1 Peek element is %d\n", peek(st));

    pop(st);
    printf("2 Peek element is %d\n", peek(st));
    pop(st);
    printf("3 Peek element is %d\n", peek(st));
    pop(st);
    printf("4 Peek element is %d\n", peek(st));

    if (isEmpty(st)) {
        printf("Stack is Empty, my friend.\n");
    } else {
        printf("Stack is Not Empty\n");
    }

    free(st->arr);
    free(st);
    return 0;
}
