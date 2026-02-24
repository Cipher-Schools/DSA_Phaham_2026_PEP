// LeetCode Problem 230 - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// Recursive - Using Inorder
void inorder(TreeNode* root, int &count, int &result, int k){
    if(!root) return;
    inorder(root->left, count, result, k);
    count++;
    if(count == k){
        result = root->val;
        return;
    }
    inorder(root->right, count, result, k);
}
int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    inorder(root, count, result, k);
    return result;
}

// Iterative - Using Stack
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*>st;
    while(root || !st.empty()){
        TreeNode* curr = root;
        while(curr ){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        if(--k == 0) return curr->val;
        root = curr->right;
    }
    return 0;
}