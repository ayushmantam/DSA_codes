#include<stdio.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};

typedef struct Stack Stack;

Stack* createStack(int size){
    Stack* stack=(Stack*)malloc(sizeof(Stack*));
    stack->size=size;
    stack->top=-1;
    return stack;
}


int peek(Stack* stack){
    if(stack->top>=0){
        return stack->top;
    }
    else{
        return -1;
    }

}

void push(Stack* stack.int element){
    if(stack->top<=stack->size){
        stack->top ++;
        stack->arr[top]=element;
    }
    else{
        printf("STack is full\n");
        return;
    }
}