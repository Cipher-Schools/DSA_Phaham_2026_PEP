// LeetCode Problem 26 - https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// Approach - 1 | One Pass | In-place | TC - O(n), SC - O(1)
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[j]!=nums[i]){
                nums[++j] = nums[i];
            }
        }
        return j+1;
    }

    // Count duplicates
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) count++;
            else nums[i-count] = nums[i];
        }
        return n-count;
    }
