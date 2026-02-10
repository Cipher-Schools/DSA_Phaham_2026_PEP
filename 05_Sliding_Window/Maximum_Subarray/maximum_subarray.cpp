// Leetcode Problem 53 - https://leetcode.com/problems/maximum-subarray/description/
// TC - O(n), SC - O(1)

// Approach - 1
int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0){
                sum = 0;
            }
            else if(sum > max){
                max = sum;
            }
        }
        if(max<0){
           max = *max_element(nums.begin(),nums.end());
        }
        return max;
    }