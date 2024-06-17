#include <stdio.h>
#include <stdlib.h>

// Structure to represent an element with a priority
typedef struct PriorityQueueElement {
    int data;
    int priority;
} PriorityQueueElement;

// Structure to represent the priority queue
typedef struct PriorityQueue {
    PriorityQueueElement elements[100]; // Maximum number of elements
    int size;
} PriorityQueue;

// Function to initialize an empty priority queue
void initializePriorityQueue(PriorityQueue* pq) {
    pq->size = 0;
}

// Function to insert an element with a priority into the priority queue
void insert(PriorityQueue* pq, int data, int priority) {
    if (pq->size == 100) {
        printf("Priority Queue is full, cannot insert\n");
        return;
    }

    int i = pq->size;
    // Find the correct position to insert the element based on priority
    while (i > 0 && pq->elements[i - 1].priority > priority) {
        pq->elements[i] = pq->elements[i - 1];
        i--;
    }

    // Insert the element at the correct position
    pq->elements[i].data = data;
    pq->elements[i].priority = priority;
    pq->size++;
}

// Function to remove and return the element with the highest priority
int removeHighestPriority(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty, cannot remove\n");
        return -1; // Return a sentinel value indicating an error
    }

    int highestPriorityData = pq->elements[0].data;

    // Remove the highest priority element by shifting elements
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }

    pq->size--;

    return highestPriorityData;
}

int main() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    insert(&pq, 10, 2);
    insert(&pq, 20, 1);
    insert(&pq, 30, 3);

    printf("Highest Priority Element: %d\n", removeHighestPriority(&pq));
    printf("Highest Priority Element: %d\n", removeHighestPriority(&pq));
    printf("Highest Priority Element: %d\n", removeHighestPriority(&pq));

    return 0;
}
