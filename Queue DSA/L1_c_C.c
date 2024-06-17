#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int size;
    int front;
    int rear;
};

typedef struct Queue Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    q->size = size;
    q->arr = (int*)malloc(size * sizeof(int));
    if (q->arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    q->front = 0;
    q->rear = 0;
    return q;
}

void push(Queue* q, int data) {
    if (q->rear == q->size) {
        printf("Queue is full\n");
    } else {
        q->arr[q->rear] = data;
        q->rear++;
    }
}

void pop(Queue* q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
    } else {
        q->arr[q->front] = -1; // You can skip this step if you don't want to mark the element.
        q->front++;

        if (q->front == q->rear) {
            q->front = 0;
            q->rear = 0;
        }
    }
}

int getFront(Queue* q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

int isEmpty(Queue* q) {
    if (q->front == q->rear) {
        return 1; // true
    } else {
        return 0; // false
    }
}

int getSize(Queue* q) {
    return q->rear - q->front;
}

int main() {
    Queue* q = createQueue(18);

    push(q, 5);
    push(q, 15);
    push(q, 25);
    push(q, 55);

    printf("Size of queue is: %d\n", getSize(q));

    pop(q);
    printf("Size of queue is: %d\n", getSize(q));

    printf("Front element is: %d\n", getFront(q));

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    free(q->arr);
    free(q);
    return 0;
}
