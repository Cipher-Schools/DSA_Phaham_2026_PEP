// LeetCoe Problem 653 - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

bool findSum(TreeNode* root, int k, unordered_set<int>seen){
    if(root == NULL)return false;
    if(seen.count(k-root->val)) return true;
    seen.insert(root->val);
    return findSum(root->left, k, seen) || findSum(root->right, k, seen);
}
bool findTarget(TreeNode* root, int k) {
    unordered_set<int>seen;
    return findSum(root, k, seen);
}
