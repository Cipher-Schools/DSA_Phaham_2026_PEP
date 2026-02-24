// LeetCode Problem 98 - https://leetcode.com/problems/validate-binary-search-tree/description/

// Approach 1 -

bool validate(TreeNode* root, long minVal, long maxVal){
    if (root == nullptr) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return validate(root->left, minVal, root->val) && validate(root->right, root->val, maxVal);
}
bool isValidBST(TreeNode* root) {
    long minVal = LONG_MIN;
    long maxVal = LONG_MAX;
    return validate(root, minVal, maxVal);
}


// Approach 2 - inorder way - inorder of bst is always sorted 
TreeNode*prev = NULL;
bool isValidBST(TreeNode* root) {
    if(root == NULL){
        return true;
    }
    if(!isValidBST(root->left)){
        return false;
    }
    if(prev && prev->val >= root->val){
        return false;
    }
    prev = root;
    if(!isValidBST(root->right)){
        return false;
    }
    return true;
}