// APPROACH 1 | recursive - dfs

int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1+countNodes(root->left) + countNodes(root->right);
}

// APPROACH - 2 | iterative bfs
