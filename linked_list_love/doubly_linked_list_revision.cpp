#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        cout << "\nNode deleted with value :" << this->data << endl;
    }
};

// in C language we use ** head insteadof *&
// in C head===*head
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtposition(Node *&head, Node *&tail, int data, int position)
{

    // Node *newNode = new Node(data);
    // can be written here
    if (head == NULL || position == 0)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 1)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    int len = getLength(head);
    if (position == len)
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }

    if (position < len)
    {
        Node *newNode = new Node(data);
        int i = 1;
        Node *prevNode = head; // prevNode Liya kyonki prev word hai na pahle se

        while (i < position)
        {
            prevNode = prevNode->next;
        }
        Node *curr = prevNode->next;

        newNode->next = curr;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        curr->prev = newNode;
    }
}
void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 0 || head == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);
    if (position == len)
    {
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    if (position < len)
    {
        int i = 1;
        Node *prevNode = head;
        while (i < position)
        {
            prevNode = prevNode->next;
            i++;
        }
        Node *curr = prevNode->next;

        prevNode->next = curr->next;
        (curr->next)->prev = prevNode;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
        return;
    }
}
int main()
{
    Node *head;
    Node *tail;
    insertAtposition(head, tail, 1, 0);
    insertAtposition(head, tail, 2, 1);
    insertAtposition(head, tail, 3, 2);
    insertAtposition(head, tail, 4, 3);
    insertAtposition(head, tail, 5, 4);
    insertAtposition(head, tail, 6, 5);
    insertAtposition(head, tail, 7, 6);
    insertAtposition(head, tail, 8, 7);
    print(head);

    int len = getLength(head);
    deleteNode(head, tail, len);
    print(head);

    deleteNode(head, tail, 1);
    print(head);

    deleteNode(head, tail, 4);
    print(head);
}
