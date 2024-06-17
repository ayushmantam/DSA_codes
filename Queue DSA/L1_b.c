#include <stdio.h>
#include <stdlib.h>

struct CirQueue {
    int size;
    int *arr;
    int front;
    int rear;
};

typedef struct CirQueue CirQueue;


CirQueue* createCirQueue(int size) {
    CirQueue* cq = (CirQueue*)malloc(sizeof(CirQueue));
    if (cq == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    cq->size = size;
    cq->arr = (int*)malloc(size * sizeof(int));
    if (cq->arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    cq->front = -1;
    cq->rear = -1;
    return cq;
}

void push(CirQueue* cq, int data) {
    if ((cq->front == 0 && cq->rear == cq->size - 1) || (cq->rear + 1 == cq->front)) {
        printf("Queue is full, cannot insert\n");
    } 
    else if (cq->front == -1) {
        cq->front = cq->rear = 0;
        cq->arr[cq->rear] = data;
    } 
    else if (cq->rear == cq->size - 1 && cq->front != 0) {
        cq->rear = 0;
        cq->arr[cq->rear] = data;
    } 
    else {
        cq->rear++;
        cq->arr[cq->rear] = data;
    }
}

void pop(CirQueue* cq) {
    if (cq->front == -1) {
        printf("Queue is empty\n");
    } 
    else if (cq->front == cq->rear) {
        cq->arr[cq->front] = -1;
        cq->front = cq->rear = -1;
    } 
    else if (cq->front == cq->size - 1) {
        cq->front = 0;
    } 
    else {
        cq->front++;
    }
}

int main() {
    CirQueue* cq = createCirQueue(5);

    push(cq, 5);
    push(cq, 15);
    push(cq, 25);
    push(cq, 55);

    pop(cq);

    // Now, you can use the circular queue as needed.

    free(cq->arr);
    free(cq);
    return 0;
}
