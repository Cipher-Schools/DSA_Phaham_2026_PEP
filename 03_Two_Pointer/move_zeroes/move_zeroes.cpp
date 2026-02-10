// LeetCode Problem 283 - https://leetcode.com/problems/move-zeroes/description/ 

void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int insertPos = 0;
        for (int num : nums) {
            if (num != 0) {
                nums[insertPos++] = num;
            }
        }
        while (insertPos < nums.size()) {
            nums[insertPos++] = 0;
        }
    }

