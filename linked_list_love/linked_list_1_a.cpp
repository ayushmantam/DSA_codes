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

// I want to insert a node right of the head of linked list
// insertion in reverse order
void insertAtHead(Node *&head, Node *&tail, int data)
{ // bireference isilye liya hai kynki hum original LL me change karna chata hu na ki copy crate karna

    // eg  of bireference input(int &num)

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

// I want to insert a node right of the end of linked list
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // check for empty linked list
    // first node ab add hone wali hai
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // step1
    Node *newNode = new Node(data);
    // step2
    tail->next = newNode;
    // step3
    tail = newNode;
}
int findlength(Node *&head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtposition(int data, int position, Node *&head, Node *&tail)
{

    //(for empty list)
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // step1:    find the position =prev and current
    int len = findlength(head);

    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    if (position >= len)
    {
        insertAtTail(head, tail, data);
    }
    
    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // step2;
    Node *newNode = new Node(data);

    // step3;
    newNode->next = curr;

    // step4:
    prev->next = newNode;
}

void deleteNode(int position, Node *&head, Node *tail)
{
    if (head == NULL)
    {
        cout << "Cant't delete, linked list is empty\n";
        return;
    }
    // deleting first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    // deleting last node
    int len = findlength(head);

    if (position <= len)
    {
        // step1:find prev
        Node *prev = head;
        int i = 1;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        // step2:
        Node *curr=prev->next;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

//INT  int main()
    // Node *prev = NULL;
    // Node *curr = head;
    // head = reverse(prev, curr);
// JO reverse linked list ka head hoga wo ye function return karega

Node *reverse(Node *&prev, Node *&curr)
{
    // base cae
    if (curr == NULL)
    {
        // LL reverse ho chuki
        return prev;
    }

    // hum first case solve krenge then recursion will take care
    Node *forward = curr->next;
    curr->next = prev;

    // recursive call
    reverse(curr, forward); // curr ko prev me aur forward ko curr me daala
}

//best and simple way
Node *reverseusingLoop(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)   
    {
        Node *temp = curr->next;   //here temp=> forward
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    //returning new head which is prev
    return prev;
}

//same code 
Node* reverseusingRecursion(Node* prev, Node* curr) {
        //base case
        if(curr == NULL) 
                return prev;

        Node* temp = curr ->next;
        curr ->next = prev;
        prev = curr;
        curr = temp;

        //recursion sambhal lega
        return reverseusingRecursion(prev, curr);
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

Node* kReverse(Node* head,int k){

    //base case call foempty LL
    if(head==nullptr){
        return NULL;
    }

    //step1: reverse first K Nodes
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    int count=0;

    while (  count<k  && curr!=nullptr)//curr hi NULL hai to reverse kise karenge
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

    return prev;
}

bool IsCircular(Node* head,Node* tail){
    //Let empty
    
    if (head==nullptr)
    {
        return NULL;
    }
    
    Node* temp=head->next;
    while (temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

Node* findMid(Node* head){
    Node* slow=head;
    Node* fast=head;

    while (fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;         
}
Node* merge(Node* left,Node* right){
    if(left==NULL)
    return right;

    if(right==NULL){
        return left;
    }

    Node* ans=new Node(-1);
    Node* temp=ans;

    while (left!=NULL&&right!=NULL)
    {
        if
    }
    
}
Node* mergeSort(Node* head){
    //base class
    if(head==NULL||head->next==NULL){
        return head;
    }
    //break linked list into 2 halves
    //after finding mid
    Node* mid=findMid(head);
    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;

    //recursive class to sort both halves
    left=mergeSort(left);
    right=mergeSort(right);

    //merge both left and right halves
    Node* result=merge(left,right);

    return result;
}
int main()
{
    // Node *head = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);

    insertAtTail(head, tail, 10);
    // insertAtTail(head, tail, 0);

    print(head);

    // cout << "\nhead: " << head->data << endl;
    // cout << "tail: " << tail->data << endl;

    // insertAtposition(101, 4, head, tail);

    // print(head);
    // cout << "\nhead: " << head->data << endl;
    // cout << "tail: " << tail->data << endl;

    // deleteNode(1, head, tail);
    // print(head);

    // cout << "\n";
    // int len = findlength(head);
    // deleteNode(len, head, tail);
    // print(head);
    // cout << "\nhead: " << head->data << endl;
    // cout << "tail: " << tail->data << endl;

    // deleteNode(len, head, tail);
    // print(head);
    // cout << "\nhead: " << head->data << endl;
    // cout << "tail: " << tail->data << endl;

    // // REVERSING LL
    // cout << endl;
    // Node *prev = NULL;
    // Node *curr = head;
    // head = reverse(prev, curr);
    // cout << endl;
    // print(head);
    // cout << endl;
    // head = reverseusingLoop(head);
    // cout << endl;
    // print(head);
    // cout << endl;

    // //K reverse
    int k=3;

    cout<<"reversing K Nodes\n";
    head=kReverse(head,k);
    print(head);

/*
        //MAKING CIRCULAR LINKED LIST
        // tail->next=head;
    int ans=IsCircular(head,tail);

    if (ans==1)
    {
        cout<<"\nLL is circular\n";
    }
    else
    {
        cout<<"\nNot circular\n";
    }
 */

    
               

}
