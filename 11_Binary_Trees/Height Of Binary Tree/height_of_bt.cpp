// APPROACH 1 - recursive - dfs
    int height(Node* root) {
        // code here
        if(root == NULL) return -1;
        return 1 + max(height(root->left), height(root->right));
    }

// APPROACH 2 - iterative - bfs
    int height(Node* root) {
    if (!root) return 0;

    // Initializing a queue to traverse
    // the tree level by level
    queue<Node*> q;
    q.push(root);
    int depth = 0;

    // Loop until the queue is empty
    while (!q.empty()) {
        int levelSize = q.size();

        // Traverse all nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();
            // enqueue their child nodes 
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        // Increment depth after traversing each level
        depth++;
    }
    return depth - 1;
}