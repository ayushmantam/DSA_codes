
#include <iostream>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node* &head)  //simply (Node* head) bhi likh skate hai sir ki aadat hai
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool detectLoop(Node* head){

    //Empty LL
    if (head==NULL)
    {
        return false;
    }
    //for map we have to include map library
    map<Node*,bool>visited;
    Node* temp=head;

    while (temp!=NULL)
    {
        //cycle is present
        if(visited[temp]==true){
            cout<<"LOOP Present on element "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;

    }
    return false;
    //TC O(n)
    //SC O(n)
}

Node* floydDetectLoop(Node* head){
    if (head==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;

    while (slow!=NULL && fast !=NULL)//slow==fast nhi  hoga to NULL to hoga hi
    {
        fast=fast->next;
        if (fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if (slow==fast)
        {
            cout<<"Present ! at(giving part of loop ) "<<slow->data<<endl;
            return slow;//but detect loop with less SC O(1) and TC O(n)
        }
    //this method give point of intersection not the starting Node
    }
return nullptr;
    
}

Node* getStartingNode(Node* head){
    if (head==NULL)
    {
        return NULL;
    }
    Node* intersection=floydDetectLoop(head);//point of insertion is the point where slow and fast meet in the loop
    Node* slow=head;//intersection mila flyoCYcleDection method 
    //staring node ke liye humne slow ko head se update kiya
    while (slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;//intersection aur slow dono starting point tak ja rhe h
    }
    
    return slow;
}
 
int main()
{
    // Node create kari
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fivth = new Node(50);

    // nodes ko link kiya
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fivth;
    fivth->next=second;

    // // printing
    // cout << "printing linked list\n";
    // print(head);
    if(detectLoop(head)==true){
        cout<<"present";
    }
    else
    {
        cout<<"NOT present\n";
    }

    floydDetectLoop(head);
    cout<<"startingNode_data "<<getStartingNode(head)->data<<endl;    
    return 0;
}
