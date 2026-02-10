// LeetCode Problem 704 - https://leetcode.com/problems/binary-search/description/

/*
Time complexity: O(logn) - Since binary search reduces the search space by half at each step, 
the maximum number of iterations required to find the target is log base 2 of n, where n is the size of the array. 
Therefore, the time complexity of binary search is O(logn).

Space complexity: O(1) - Binary search only uses a constant amount of additional space for the two pointers and the 
middle index variable, so the space complexity is O(1).

*/

 int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target>nums[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }