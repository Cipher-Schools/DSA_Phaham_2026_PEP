// LeetCode Problem 35 - https://leetcode.com/problems/search-insert-position/
// TC - O(log(n)), SC -O(1)

    int search(vector<int>& nums, int start, int end, int target){
        if(start > end)return start;
        int mid = start + (end-start)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return   search(nums, mid+1, end, target);
        else return search(nums, start, mid-1, target);
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return search(nums, 0, n-1, target);
    }
