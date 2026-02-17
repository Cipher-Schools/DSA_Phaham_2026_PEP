// APPROACH 1 | recursive - dfs

int countLeaves(Node* root) {
        // write code here
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return countLeaves(root->left) + countLeaves(root->right);
}

// APPROACH 2 | iterative - bfs
