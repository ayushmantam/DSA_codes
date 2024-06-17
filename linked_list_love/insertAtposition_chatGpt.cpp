#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtPosition(Node*& head, int data, int position) {
    Node* newNode = new Node(data);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* prevNode = nullptr;
    Node* currentNode = head;
    int currentPosition = 0;

    while (currentNode != nullptr && currentPosition < position) {
        prevNode = currentNode;
        currentNode = currentNode->next;
        currentPosition++;
    }

    if (currentPosition == position) {
        prevNode->next = newNode;
        newNode->next = currentNode;
    } else {
        std::cout << "Position out of range." << std::endl;
        delete newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; ++i) {
        insertAtPosition(head, i, i - 1);
    }

    std::cout << "Original List: ";
    displayList(head);

    insertAtPosition(head, 10, 2);  // Insert 10 at position 2
    std::cout << "List after inserting 10 at position 2: ";
    displayList(head);

    return 0;
}
