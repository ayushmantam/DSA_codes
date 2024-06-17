/*

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        // If both subtrees are empty, they are symmetric.
        if (leftSubtree == NULL && rightSubtree == NULL) {
            return true;
        }

        // If one of the subtrees is empty while the other is not, they are not symmetric.
        if (leftSubtree == NULL || rightSubtree == NULL) {
            return false;
        }

        // Check if the values of the current nodes are equal, and recursively check subtrees.
        return (leftSubtree->val == rightSubtree->val) &&
               isMirror(leftSubtree->left, rightSubtree->right) &&
               isMirror(leftSubtree->right, rightSubtree->left);
    }
    bool isSymmetric(TreeNode* root) {
        
        return isMirror(root->left,root->right);

    }

*/