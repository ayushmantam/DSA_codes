/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sum(TreeNode* root,int &totalSum,int currentSum){
      if(root==NULL){
          totalSum += currentSum;
          cout<<totalSum<<" "<<currentSum<<endl;
          return;
      }
      currentSum =currentSum*10 + root->val ;


      sum(root->left,totalSum,currentSum);


      sum(root->right,totalSum,currentSum);

    }
    int sumNumbers(TreeNode* root) {
        int totalSum=0;
        int currentSum=0;

        sum(root,totalSum,currentSum);

        return totalSum;
    }
};