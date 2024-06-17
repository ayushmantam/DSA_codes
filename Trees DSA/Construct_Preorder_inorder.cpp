/**
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

typedef TreeNode Node;

int findPosition(vector<int>arr, int n, int element) {
        for(int i=0; i<n; i++) {               
                if(arr[i] == element) {
                        return i;
                }
        }
        return -1;
}

    Node* buildTreeFromPreOrderInOrder(vector<int>&inorder, vector<int>&preorder, int size, int &preIndex, int inorderStart, int inorderEnd) {

        //base case
        if(preIndex >= size || inorderStart > inorderEnd) {
                return NULL;
        }

        //Step A:
        int element = preorder[preIndex++];
        Node* root = new Node(element);
        int pos = findPosition(inorder, size, element);  //element ki postion inorder me find kari

        //step B: root->left solve
        root->left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos-1);
        //Step C: root->right solve
        root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos+1, inorderEnd);

        return root;
}  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        int size=inorder.size();
        int preindex=0;
        int inorderStart=0;
        int inorderEnd=size-1;
        Node* ans=buildTreeFromPreOrderInOrder(inorder,preorder,size,preindex,inorderStart,inorderEnd);

        return ans;
    }
};