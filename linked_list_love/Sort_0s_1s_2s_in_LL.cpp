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

//WHEN DATA REPLACEMENT ALLOWDED
/*
void sortList(Node* head){
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;
    Node* temp=head;
    while (temp!=NULL)
    {
        if (temp->data==0)
        {
            zeroCount++;
        }
        else if (temp->data==1)
        {
            oneCount++;
        }
        else{
            twoCount++;
        }
        temp=temp->next;
    }
    temp=head;
     while (temp!=NULL)
     {
        if (zeroCount!=0)
        {
            temp->data=0;
            temp=temp->next;
            zeroCount--;
        }
        else if (oneCount!=1)
        {
            temp->data=1;
            temp=temp->next;
            oneCount--;

        }
        else  if(twoCount!=0)
        {
            temp->data=2;
            temp=temp->next;
            twoCount--;
        }

        // temp=temp->next;
     }
     return;
     
}
*/ 

void insertAtTail(Node* &tail,Node* curr){
    tail->next=curr;
    tail=curr;
    return;
}

//WHEN DATA REPLACEMENT NOTTT ALLOWDED
void sortList2(Node* head){
    Node* zeroHead=new Node(-1);//dummy
    Node* zeroTail=zeroHead;//insert at tail ho raha hai isiliye humne tail banaya
    Node* oneHead=new Node(-1);//dummy
    Node* oneTail=oneHead;
    Node* twoHead=new Node(-1);//dummy
    Node* twoTail=twoHead;

    Node* curr=head;

    //can seperaten list 0s,1s,2s
    while (curr!=NULL)
    {
        int value=curr->data;
        if (value==0)
        {
            insertAtTail(zeroTail,curr);
        }
        else if (value==1)
        {
            insertAtTail(oneTail,curr);
        }
        else if (value==2)
        {
            insertAtTail(twoTail,curr);
        }
        curr=curr->next;
    }

    //merge 3 sublist

    // zeroTail->next=oneHead->next;
    // oneTail->next=twoHead->next;
    // twoTail->next=NULL;  iss tarike me dikkat dekh notes me

    if (oneHead->next!=NULL)
    {
        zeroTail->next=oneHead->next;
    }
    else
    {
        //1st empty
        zeroTail->next=twoHead->next;
    }

    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    
    //setup head
    head=zeroHead->next;

    //delete
    delete zeroHead;
    delete oneHead;
    delete twoHead;


    return;
}
int main()
{ 
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    print(head);
    cout<<endl;
    sortList2(head);
    print(head);
    
}    