// LeetCode Problem 700 - https://leetcode.com/problems/search-in-a-binary-search-tree/description/

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL){
        return NULL;
    }
    if(root->val == val){
        return root;
    }
    else if(root->val > val){
        return searchBST(root->left, val);
    }
    else if(root->val < val){
        return searchBST(root->right, val);
    }
    return NULL;
}

// GFG Problem - https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1
bool search(Node* root, int key) {
    // code here
      if(root == NULL) return false;
      if(key == root->data) return true;
      else if(key<root->data) return search(root->left, key);
      else return search(root->right, key);
}