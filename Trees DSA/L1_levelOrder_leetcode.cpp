/*

n 
void levelTrav(TreeNode* root, vector<vector<int>>& levelorder) {
    if (!root) return; // Handle the case of an empty tree.

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Get the number of nodes at the current level.
        vector<int> currentorder; // Create a new vector for the current level.

        for (int i = 0; i < levelSize; ++i) {
            Node* temp = q.front();
            q.pop();

            currentorder.push_back(temp->val);

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            } 
        }

        levelorder.push_back(currentorder);
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levelorder;
    levelTrav(root, levelorder);

    return levelorder;
}

*/