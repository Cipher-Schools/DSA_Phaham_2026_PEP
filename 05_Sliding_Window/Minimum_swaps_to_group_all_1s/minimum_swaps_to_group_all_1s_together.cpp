// LeetCode Problem 2134 - https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

// TC - O(n), SC -O(1)
int minSwaps(vector<int>& nums) {
    int n = nums.size();
    int totalOnes = 0;
    for(int i=0;i<n;i++){
        if(nums[i] == 1) totalOnes++;
    }
    if(totalOnes == 0 || totalOnes == n){
        return 0;
    }
    int currOnes = 0;
    for(int i=0;i<totalOnes;i++){
        if(nums[i] == 1)currOnes++;
    }
    int maxOnes = 0;

    for(int i=0;i<n;i++){
        currOnes -= nums[i];
        currOnes += nums[(i+totalOnes)%n];
        maxOnes = max(maxOnes, currOnes);
    }
    return totalOnes - maxOnes;
}