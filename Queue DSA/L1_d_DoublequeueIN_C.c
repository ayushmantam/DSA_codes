#include <stdio.h>
#include <stdlib.h>

typedef struct Deque {
    int *arr;
    int size;
    int front;
    int rear;
} Deque;

Deque* createDeque(int size) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->size = size;
    deque->arr = (int*)malloc(sizeof(int) * size);
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

void pushRear(Deque* deque, int data) {
    if ((deque->front == 0 && deque->rear == deque->size - 1) ||
        (deque->front == deque->rear + 1)) {
        printf("Queue is full, cannot insert\n");
        return;
    } 
    else if (deque->front == -1) {
        deque->front = deque->rear = 0;
    } 
    else if (deque->rear == deque->size - 1 && deque->front != 0) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->arr[deque->rear] = data;
}

void pushFront(Deque* deque, int data) {
    if ((deque->front == 0 && deque->rear == deque->size - 1) ||
        (deque->front == deque->rear + 1)) {
        printf("Queue is full, cannot insert\n");
        return;
    } else if (deque->front == -1) {
        deque->front = deque->rear = 0;
    } else if (deque->front == 0 && deque->rear != deque->size - 1) {
        deque->front = deque->size - 1;
    } else {
        deque->front--;
    }
    deque->arr[deque->front] = data;
}

void popFront(Deque* deque) {
    if (deque->front == -1) {
        printf("Queue is empty\n");
    } else if (deque->front == deque->rear) {
        deque->arr[deque->front] = -1;
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == deque->size - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
}

void popRear(Deque* deque) {
    if (deque->front == -1 && deque->rear == -1) {
        printf("Queue is empty\n");
    } else if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = deque->size - 1;
    } else {
        deque->rear--;
    }
}

int main() {
    Deque* deque = createDeque(5);
    pushRear(deque, 1);
    pushRear(deque, 2);
    pushFront(deque, 3);
    pushFront(deque, 4);
    popFront(deque);
    popRear(deque);

    // Printing elements in the deque
    int i;
    for (i = deque->front; i != deque->rear; i = (i + 1) % deque->size) {
        printf("%d ", deque->arr[i]);
    }
    printf("%d\n", deque->arr[i]);

    free(deque->arr);
    free(deque);
    return 0;
}
