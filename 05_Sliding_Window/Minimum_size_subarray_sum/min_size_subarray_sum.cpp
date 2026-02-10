// LeetCode Problem 209 - https://leetcode.com/problems/minimum-size-subarray-sum/description/
// Variable Window
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = 0;
    int ans = INT_MAX;
    int sum = 0;
    while(right < n){
        sum += nums[right];
        while(sum >= target){
            ans = min(ans, right - left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return ans==INT_MAX?0:ans;
}