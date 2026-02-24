// LeetCode Problem 701 - https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

// Recursive - 
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL){
        TreeNode* newNode = new TreeNode(val);
        return newNode;
    }
    if(root->val > val){
        root->left = insertIntoBST(root->left, val);
    }
    if(root->val < val){
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}


// Iterative -
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* newNode = new TreeNode(val);
    if(!root) return newNode;

    TreeNode* curr = root;
    TreeNode* parent = NULL;

    while(curr){
        parent = curr;
        if(val < curr->val) curr = curr->left;
        else if(val > curr->val) curr = curr->right;
        // else 
    }

    if(val < parent->val) parent->left = newNode;
    if(val > parent->val) parent->right = newNode;
    return root;
}