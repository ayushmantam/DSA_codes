#include<iostream>
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

Node* solve(Node* first,Node* second){
    //if only one element is present in first list
    if (first->next==NULL)
    {
        first->next=second;
        return first;
    }
    
    Node* curr1=first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=curr2->next;

    while (next1 != NULL && curr2 !=NULL)
    {
        if (curr2->data >=curr1->data && curr2->data <= next1->data)
        {
        //add node in between first node    
        curr1->next=curr2;
        curr2->next=next1;

        //update pointers 
        curr1=next1;
        // next1=curr1->next; next1 ki to defination hi yhi hai
        curr2=next2;
        }
        else
        {
            //curr1 and curr2 ko aage badhana hai
            curr1=curr1->next;
            next1=next1->next;

            if (next1==NULL)
            {
                curr1->next=curr2;
                return first;
            }

            
        }
        
    }
    
}
Node* Merge_LL(Node* first,Node* second){
    //first LL is empty
    if(first==NULL){
        return second;
    }
    if (second==NULL)
    {
        return first;
    }
    
    //agar second list ka 1st element first list ke 1st element se bhi chota ho to
    //second wali list ko fisrt maan lege
    if (first->data  <=second->data)
    {
        return solve(first,second);//first ko first rahne diya second ko second
    }
    else
    {
        return solve(second,first);
        //second ko first banaya aur first ko second
    }
}
