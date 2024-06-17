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

// METHOD 1  TC O(n)   SC O(n)
/*
class Solution{
    private:
    bool checkPallindrome(vector<int> arr){
        int n=arr.size();
        int s=0;
        int e=arr.size()-1;
        while (s<=e)
        {
            if (arr[s]!=arr[e])
            {
                return 0;
            }
            else
            {
                s++;
                e--;
            }
        }
            return 1;

    }

    public:
    bool isPallindrome(Node* head){
        vector<int> arr;
        Node* temp=head;
        while (temp!=NULL)
        {
            arr.push_back(temp->data);
            temp=temp->next;
        }
        return checkPallindrome(arr);
    }
};
*/
// METHOD 2  TC O(n)   SC O(1)
class Solution
{
private:
    Node *getMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
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
    bool isPallindrome(Node *head)
    {
        if (head->next == NULL)//only one Node
        {
            return true;
        }

        // step1:  find middle
        Node *middle = getMid(head);

        // step2: reverse linked list after middle
        Node *temp = middle->next;
        middle->next = reverse(temp);

        // step3 : compare both halves
        Node *head1 = head;
        Node *head2 = middle->next;
        while (head2->next != nullptr)
        {
            if (head1->data == head2->data)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            else
            {
                return false;
            }
        }

        // step4: repeat step2 (convert LL like initial form)
        temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }
};