#include <iostream>
#include <vector>
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

class Solution{
    private:
    Node *reverse(Node *temp)
    {
        Node *prev = NULL;
        Node *curr = temp;
        Node *forward = NULL;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    public:
    Node* addTwoLists(Node* first,Node* second){
        // step1: reverse both the lists
        Node* first=reverse(first);  //45
        Node* second=reverse(second); //345

        //step2: add2 LL
        // Node* ans=add(first,second); 
       //093
        //step3:
        ans=reverse(ans); //390

        return ans;
    }
};