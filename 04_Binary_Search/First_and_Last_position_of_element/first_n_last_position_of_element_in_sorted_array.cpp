// LeetCode Problem 34 - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

int binary_search(vector<int>& nums, int target, bool flag){
        int n = nums.size();
        int start = 0, end = n-1;
        int ans = -1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans = mid;
                if(flag){ 
                    start = mid+1;
                }
                else{
                    end = mid - 1;
                }
            }
            else if(nums[mid]<target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left  = binary_search(nums, target, false);
        int right = binary_search(nums, target, true);

        return {left, right};
    }