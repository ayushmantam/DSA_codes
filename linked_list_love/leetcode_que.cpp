/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    typedef ListNode Node;
    // typedef val data;
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
    bool isPalindrome(ListNode* head) {
        Node* head1=head;
        Node* middle=getMid(head);
        Node* head2=reverse(middle->next);

        //checking
        while(head2!=NULL){
          if(head1->val==head2->val){
            head1=head1->next;
            head2=head2->next;
          }
          else{
            return false;
          }

        }
        return true;
    }
};