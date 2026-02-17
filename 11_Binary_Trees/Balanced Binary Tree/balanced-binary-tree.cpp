// APPROACH 1 - recursive - dfs

int balanced(TreeNode* root){
        if(root == NULL) return 0;
        int leftH = balanced(root->left);
        if(leftH == -1) return -1;
        int rightH = balanced(root->right);
        if(rightH == -1) return -1;

        if(abs(leftH-rightH)>1) return -1;
        return 1+max(balanced(root->left), balanced(root->right));
    }
    bool isBalanced(TreeNode* root) {
        return balanced(root)!=-1;
    }

    // APPROACH 2 - iterative - bfs


