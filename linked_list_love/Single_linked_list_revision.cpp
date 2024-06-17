#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "\nNode with value " << this->data << " deleted" << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
};

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
    // for Empty linked list
    if (head == NULL || position == 0)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // For position 1 ie insertion at head
    if (position == 1)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    }

    // Insertion At tail OR position==len

    int len = getLength(head);
    if (position == len)
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
        return;
    }

    // Insertion At any position

    if (position <= len)
    {
        int i = 1;
        Node *prev = head;
        while (i < position)
        {
            prev = prev->next;
        }
        Node *curr;
        curr = prev->next;

        // creating newNode
        Node *newNode = new Node(data);
        newNode->next = curr;
        prev->next = newNode;

        return;
    }
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Linked List is empty\n";
    }

    // Deletetion from head;

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // Deletetion from tail

    int len = getLength(head);

    if (position == len)
    {
        int i = 1;
        Node *prev = head;
        while (i < position)
        {
            prev = prev->next;
            i++;
        }
        Node *temp = tail;
        prev->next = NULL;
        tail = prev;
        delete temp;
    }

    //deletion at middle
    if (position<len)
    {
        int i = 1;
        Node *prev = head;
        while (i < position)
        {
            prev = prev->next;
            i++;
        }
        Node* curr=prev->next;
        prev->next=curr->next;
        curr->next=NULL;
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
    print(head);
    deleteNode(2,head,tail);
    print(head);

}