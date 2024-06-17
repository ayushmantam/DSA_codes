#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node; // Simplified typedef

void insertAtHead(Node **head, Node **tail, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    
    *head = newNode;
    if (*tail == NULL) {
        *tail = newNode;
    }
}

void insertAtTail(Node **head, Node **tail, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
//dont want to change in actual
int findLength(Node *head) {
    int len = 0;
    Node *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int data, int position, Node **head, Node **tail) {
    if(*head==NULL){
        Node *newNode=(Node*)malloc(sizeof(Node));
        newNode->data=data;
        newNode->next=NULL;
        *head=newNode;
        *tail=newNode;
        return;
    }

    int len = findLength(*head);

    if (position == 0) {
        insertAtHead(head, tail, data);
        return;
    }

    if (position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    Node *prev = *head;
    for (int i = 1; i < position; i++) {
        prev = prev->next;
    }
    Node *curr = prev->next;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = curr;

    prev->next = newNode;
}

void deleteNode(int position, Node **head, Node **tail) {
    if (*head == NULL) {
        printf("Can't delete, linked list is empty\n");
        return;
    }

    if (position == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
        return;
    }

    int len = findLength(*head);
    if (position >= len) {
        return;
    }

    Node *prev = *head;
    for (int i = 1; i < position; i++) {
        prev = prev->next;
    }
    Node *curr = prev->next;

    prev->next = curr->next;
    curr->next = NULL;
    free(curr);
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(&head, &tail, 20);
    insertAtHead(&head, &tail, 30);
    insertAtHead(&head, &tail, 40);
    insertAtHead(&head, &tail, 50);
    insertAtHead(&head, &tail, 60);

    insertAtTail(&head, &tail, 10);

    print(head);

    // InsertAtPosition(101, 4, &head, &tail);
    // Print(head);

    // DeleteNode(1, &head, &tail);
    // Print(head);

    // int len = FindLength(head);
    // DeleteNode(len, &head, &tail);
    // Print(head);

    // DeleteNode(len, &head, &tail);
    // Print(head);

    // head = Reverse(head);
    // Print(head);

    // head = ReverseUsingLoop(head);
    // Print(head);

    // int k = 3;
    // printf("Reversing K Nodes\n");
    // head = KReverse(head, k);
    // Print(head);

    return 0;
}
