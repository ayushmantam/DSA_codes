#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    ~Node()
    {
        cout << "Node with value: " << this->data << " deleted";
    }
};
void print(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL) // LL is empty
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        // LL is non-empty
        // step1:create a Node
        Node *newNode = new Node(data);
        // step2:
        newNode->next = head;
        // step3:
        head->prev = newNode;
        // step4:
        head = newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == nullptr) // LL is empty
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not empty
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not empty
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }
        int len = getLength(head);

        if (position >= len)
        {
            insertAtTail(head, tail, data);
            return;
        }
        // insertion at middle
        // step1:find prev ans curr
        Node *prevNode = head;
        int i = 1;
        while (i < position - 1)
        {
            prevNode = prevNode->next;
            i++;
        }
        Node *curr = prevNode->next;

        // step2: create a node
        Node *newNode = new Node(data);

        // step3:four links linked
        
        prevNode->next = newNode;
        newNode->prev = prevNode;
        curr->prev = newNode;
        newNode->next = curr;
    }
}

void deleteFromPos(Node *&head, Node *tail, int position)
{
    if (head == NULL)
    {
        cout << "Linked list is empty\n";
        return;
    }
    if (head->next == NULL)
    {
        // single node
        Node *temp = head;
        head = NULL;
        delete temp;
        return;
    }
    int len = getLength(head);
    if (position > len)
    {
        cout << "please enter a valid position\n";
        return;
    }

    if (position == 1)
    {
        // want to delete the first node
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if (position == len) // means we want to delete last node
    {
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }
    // delete from middle of linked list

    // step1: find left ,curr, right;

    int i = 1;
    Node *left = head;
    while (i < position - 1)
    {
        left = left->next;
        i++;
    }
    Node *curr = left->next;
    Node *right = curr->next;

    // step2::
    left->next = right;
    // step3::
    right->prev = left;
    // step4:

    curr->prev = NULL;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

//this code and resverseusingrecursion  code same same 
Node* reverse(Node* &prev,Node* &curr){
    //base case;
    if (curr==NULL)
    {
        return prev; //bcoz last me prev head ban jata hai
    }
    // one case solve then recursive call wil take care
    Node* forward=curr->next;
    curr->next=prev;

    return reverse(curr,forward);

}

Node* reverseusingLoop(Node *head){
    Node* prev=NULL;
    Node* curr=head;
//here temp==forward pointer
    while (curr!=NULL)
    {
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
Node* reverseusingRecursion(Node* prev,Node* curr){
    //base case
    if (curr==NULL)
    {
        return prev;
    }
    Node* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;

    //recursion sambhal lega
 
    reverseusingRecursion(prev,curr);
}

Node* kReverse(Node* head,int k){

    //base case call
    if(head==nullptr){
        return NULL;
    }

    //step1: reverse first K Nodes
    Node* forward=NULL;
    Node* prev=NULL;
    Node* curr=head;
    int count=0;

    while (count<k  && curr!=nullptr)//curr hi NULL hai to reverse kise karenge
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;//curr ko prev banaya
        curr=forward; //forward ko curr banaya
        count++;
    }
    //step2: recursion dekhlega aage ka 
    if (forward!=NULL)
    {
        head->next=kReverse(forward,k);
    }
    
    //step3: return head of reverse list
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    Node *head = first;
    Node *tail = third;
    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);
    cout << endl;
    insertAtHead(head, tail, 101);
    cout << endl;

    print(head);

    insertAtTail(head, tail, 501);
    cout << endl;
    print(head);

    insertAtPosition(head, tail, 9077, 4);
    cout << endl;
    print(head);
    cout << endl;

    // deleteFromPos(head, tail, 3);
    // cout << "\nAfter deletion ";
    // print(head);
    // cout<<endl;
    // Node* prev=NULL;
    // Node* curr=head; 
    // head=reverse(prev,curr);
    // print(head);
    // cout<<endl;

    // head=reverseusingLoop(head);
    // print(head);
    // cout<<endl;
    // return 0;

    head=kReverse(head,3);
    print(head);
}