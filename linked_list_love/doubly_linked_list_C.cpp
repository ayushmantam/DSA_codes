#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node Node;

Node* createNode(int data) {
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;

}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int getLength(Node *head) {
    int len = 0;
    Node *temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node **head, Node **tail, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtTail(Node **head, Node **tail, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void insertAtPosition(Node **head, Node **tail, int data, int position) {
    if (*head == NULL) {
        Node *newNode = createNode(data);
        *head = newNode;
        *tail = newNode;
    } else {
        if (position == 1) {
            insertAtHead(head, tail, data);
            return;
        }
        int len = getLength(*head);
        if (position >= len) {
            insertAtTail(head, tail, data);
            return;
        }
        Node *prevNode = *head;
        int i = 1;
        while (i < position - 1) {
            prevNode = prevNode->next;
            i++;
        }
        Node *curr = prevNode->next;
        Node *newNode = createNode(data);
        prevNode->next = newNode;
        newNode->prev = prevNode;
        curr->prev = newNode;
        newNode->next = curr;
    }
}

void deleteFromPos(Node **head, Node **tail, int position) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        Node *temp = *head;
        *head = NULL;
        free(temp);
        return;
    }
    int len = getLength(*head);
    if (position > len) {
        printf("Please enter a valid position\n");
        return;
    }
    if (position == 1) {
        Node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        temp->next = NULL;
        free(temp);
        return;
    }
    if (position == len) {
        Node *temp = *tail;
        *tail = (*tail)->prev;
        temp->prev = NULL;
        (*tail)->next = NULL;
        free(temp);
        return;
    }
    int i = 1;
    Node *left = *head;
    while (i < position - 1) {
        left = left->next;
        i++;
    }
    Node *curr = left->next;
    Node *right = curr->next;
    left->next = right;
    right->prev = left;
    curr->prev = NULL;
    curr->next = NULL;
    free(curr);
}

Node* reverse(Node* prev, Node* curr) {
    if (curr == NULL) {
        return prev;
    }
    Node* forward = curr->next;
    curr->next = prev;
    return reverse(curr, forward);
}

Node* reverseusingLoop(Node *head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* temp;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        curr->prev = temp;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* reverseusingRecursion(Node* prev, Node* curr) {
    if (curr == NULL) {
        return prev;
    }
    Node* temp = curr->next;
    curr->next = prev;
    curr->prev = temp;
    return reverseusingRecursion(curr, temp);
}

Node* kReverse(Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    Node* forward = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;
    while (count < k && curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        curr->prev = forward;
        prev = curr;
        curr = forward;
        count++;
    }
    if (forward != NULL) {
        head->next = kReverse(forward, k);
    }
    return prev;
}

int main() {
    Node *first = createNode(10);
    Node *second = createNode(20);
    Node *third = createNode(30);

    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    printf("Original List: ");
    print(first);
    printf("\n");

    insertAtHead(&head, &tail, 101);
    printf("After inserting at the head: ");
    print(head);
    printf("\n");

    insertAtTail(&head, &tail, 501);
    printf("After inserting at the tail: ");
    print(head);
    printf("\n");

    insertAtPosition(&head, &tail, 9077, 4);
    printf("After inserting at position 4: ");
    print(head);
    printf("\n");

    deleteFromPos(&head, &tail, 3);
    printf("After deleting at position 3: ");
    print(head);
    printf("\n");

    head = reverse(NULL, head);
    printf("After reversing the list using recursion: ");
    print(head);
    printf("\n");

    head = reverseusingLoop(head);
    printf("After reversing the list using a loop: ");
    print(head);
    printf("\n");

    head = reverseusingRecursion(NULL, head);
    printf("After reversing the list again using recursion: ");
    print(head);
    printf("\n");

    head = kReverse(head, 3);
    printf("After k-reversing the list in groups of 3: ");
    print(head);
    printf("\n");

    return 0;
}
