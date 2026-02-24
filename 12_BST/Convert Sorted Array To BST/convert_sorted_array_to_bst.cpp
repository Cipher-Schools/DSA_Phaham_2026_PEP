// LeetCode Problem 108 - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

TreeNode* convertToBST(vector<int>& nums, int start, int end) {
    int mid = start+ (end-start)/2;
    // int mid = (start+ end)/2;
    if(start>end) return NULL;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = convertToBST(nums, start, mid-1);
    root->right = convertToBST(nums, mid+1, end);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    return convertToBST(nums, 0, n-1); 
}
