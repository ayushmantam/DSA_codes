#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue node
typedef struct QNode {
    int key;   //key===data 
    struct QNode* next;
} QNode;

// Define the queue structure
typedef struct Queue {
    QNode* front;
    QNode* rear;
} Queue;

// A utility function to create a new linked list node
QNode* newNode(int k) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

// A utility function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add a key k to the queue
void enQueue(Queue* q, int k) {
    QNode* temp = newNode(k);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a key from the given queue
void deQueue(Queue* q) {
    if (q->front == NULL)
        return;

    QNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}


int main() {
    Queue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    deQueue(q);
    printf("Queue Front: %d\n", ((q->front != NULL) ? (q->front)->key : -1));
    printf("Queue Rear: %d\n", ((q->rear != NULL) ? (q->rear)->key : -1));
    return 0;
}
