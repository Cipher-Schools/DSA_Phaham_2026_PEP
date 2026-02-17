// recursive way - dfs
TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        swap(root->left, root->r  ight);
        invertTree(root->left);
        invertTree(root->right);
        return root;????
    }

//iterative - bfs
