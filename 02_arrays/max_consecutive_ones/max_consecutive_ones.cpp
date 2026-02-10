// Leetcode problem 485 - https://leetcode.com/problems/max-consecutive-ones/description/

 int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0, max_count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }
            else{
                count = 0;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
    