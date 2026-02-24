// LeetCode Problem 938 - https://leetcode.com/problems/range-sum-of-bst/description/

int rangeSumBST(TreeNode* root, int low, int high) {
    if(root == NULL) return 0;
    int sum = 0;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();

        if(node->val >= low && node->val <= high){
            sum += node->val;
        }
        if(node->val > low && node->left){
            st.push(node->left);
        }
        if(node->val < high && node->right){
            st.push(node->right);
        }
    }
    return sum;
}
