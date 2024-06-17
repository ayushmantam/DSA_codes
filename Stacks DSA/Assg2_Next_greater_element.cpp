#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
    public:
   vector<int> nextSmallerNodes(ListNode* head){
    vector<int>ll;
    while (head)
    {
        ll.push_back(head->val);
        head=head->next;
    }

    stack<int>st;
    vector<ans>(ll.size()); //init 0
    
   }
    
}