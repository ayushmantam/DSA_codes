// approch 1 TC O(n^2)
// approach 2 TC O(n)
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
   Node *random;  //or  *arb
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random=NULL;
    }
};
/*
class Solution
{
private:
    void insertAtTail(Node *head, Node *tail, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        return;
    }

public:
    Node *copyList(Node *head)
    {
        // step1: create a clone list
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step2: create a map
        map<Node *, Node *> oldToNewNode;
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL) // kabhi kabhi koi condtion ki need nhi hoti hum bas practice ke liye daal dete hai
        {
            //mapping of originalNode to cloneNode by oldToNewNode map
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        //re intialization
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL)
        {
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next; 
        }

        return cloneHead;
        
    }
    
};*/


//Approach 3 TC O(n)  SC O(1)
class Solution{
    private:
    void insertAtTail(Node* &head,Node* &tail,int d){
        Node* newNode=new Node(d);
        if (head==NULL)
        {
            head=newNode;
            tail=newNode;
        
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
        return;
        
    }
    public:
    Node* copyList(Node *head){
        //step1: create a clone List
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;

        Node* temp=head;
        while (temp!=NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        

        //step2: cloneNode odd in between Original List
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while (originalNode!=NULL && cloneNode!=NULL)
        {
            Node* next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;

            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next;
        }
        
        //step3: random poiinter copy
        Node* temp=head;
        while (temp!=NULL)
        {
            if (temp->next!=NULL)
            {
                if (temp->random!=NULL)
                {
                    temp->next->random=temp->random->next;
                }
                
            }
            
            temp->next->random=temp->random->next;
        }
         
        //step4: revert changes done in step 2


        //step5: return ans
    }
}