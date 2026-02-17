// APPROACH 1 - recursive - dfs

    void preorder(TreeNode* root, vector<int>&ans) {
        if(root == NULL) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root, ans);
        return ans;
    }


// APPROACH 2 - iterative - bfs
  vector<int> bfs(TreeNode* root) {
    vector<int> nodes;
    if (!root) return nodes;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        nodes.push_back(curr->val);

        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    return nodes;
}

    // APPROACH 3 - Morris Traversal
    