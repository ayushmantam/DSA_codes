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
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// return typeof this pointer is Node

//Tortise Algorithem
Node *getMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty\n";
    }
    if (head->next == NULL)
    {
        // only one node in LL
        return head;
    }

    // LL have one or more node

    else // hum else ke baahar bhi likh sakte hai
    {
        Node *slow = head;
        Node *fast = head;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next; // de placeek sath aage nhi bada sakte
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next; // slow tabhi aage bdhega jab fast do step aage bhadhga
            }
        }
        return slow;
    }
}

int getLength(Node* head){
    int len=0;
    Node* temp=head;
    while (temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
Node* reverseKNodes(Node* &head,int k){
    if (head==NULL)
    {
        cout<<"LL is empty\n";
        return NULL;
    }
    int  len= getLength(head);
    if (k>len)
    {
        cout<<"Enter valid value for k\n";
        return head;
    }
    //it means number of nodes in LL is >>k

    //step A:reverse first k nodes of LL
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=curr->next;///doubt it should be Node* forward=NULL;
    int count=0;
    while (count<k)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        count++;
    }

    //step B:reursive call
    if (forward!=NULL)
    {
        //we stil have nodes left to reverse
        head->next=reverseKNodes(forward,k);

    }
    
    //step C:
    
    
}
int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;
    // fifth->next = NULL;
 /*   print(head);

    cout << "Middle Node is: " << getMiddle(head)->data << endl;
//two case odd and even no of terms
    // 10 20 30 40 50 60
    // Middle Node is: 40
    // 10 20 30 40 50
    // Middle Node is: 30
*/


    return 0;
}
