//Remove duplicate from sorted linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Node()
    // {
    //     this->data = 0;
    //     this->next = NULL;
    // }

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node *&head, Node *&tail, int data)
{ // bireference isilye liya hai kynki hum original LL me change karna chata hu na ki copy crate karna

    // eg of bireference input(int &num)

    // check for empty linked list
    // first node ab add hone wali hai
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // step1:create a new Node
    Node *newNode = new Node(data);
    // step2:
    newNode->next = head;
    // step3:
    head = newNode; // because head staring of  linked list darshata hai
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void RemoveDuplicate_sorted(Node* head){
    if (head==NULL)
    {
        return;
    }
    Node* curr=head;
    while (curr->next!=NULL)
    {
        if (curr->next!=nullptr &&curr->data==(curr->next)->data)
        {
            Node* next_next=curr->next->next;
            Node* NodeToDelete=curr->next;
            delete(NodeToDelete);
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }   
    }
    return;
}

int main()
{ 
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    print(head);
    cout<<endl;
    RemoveDuplicate_sorted(head);
    print(head);
}    