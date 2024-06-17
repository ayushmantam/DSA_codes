/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      //step 1
      if(root==NULL){
        return NULL;
      }

      //step 2 check for p and q
      if(root->val==p->val){
        return p;  
      }
      if(root->val==q->val){
        return q;
      }

      TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
      TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);


      if(leftAns==NULL&&rightAns==NULL){
        return NULL;
      }
      else if(leftAns!=NULL&&rightAns==NULL){
        return leftAns;
      }

      else if(leftAns==NULL&& rightAns!=NULL){
        return rightAns;
      }
      else{ //leftAns and  rightAns both are Not NULL
        return root;//matlab root hi LCA hai
      }
    }
};


*/