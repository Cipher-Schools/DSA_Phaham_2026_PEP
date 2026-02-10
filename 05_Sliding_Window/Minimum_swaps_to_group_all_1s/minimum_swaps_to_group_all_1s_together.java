// LeetCode Problem 2134 - https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

// TC - O(n), SC -O(1)
public class minimum_swaps_to_group_all_1s_together {
  
    public int minSwaps(int[] nums) {
        int n = nums.length;

        int totalOnes = 0;
        for (int num : nums) {
            if (num == 1) totalOnes++;
        }

        // If all 0s or all 1s, no swaps needed
        if (totalOnes == 0 || totalOnes == n) return 0;

        // Count 1s in the first window of size totalOnes
        int currOnes = 0;
        for (int i = 0; i < totalOnes; i++) {
            if (nums[i] == 1) currOnes++;
        }

        int maxOnes = currOnes;

        // Sliding window over circular array
        for (int i = 0; i < n; i++) {
            currOnes -= nums[i];
            currOnes += nums[(i + totalOnes) % n];
            maxOnes = Math.max(maxOnes, currOnes);
        }

        return totalOnes - maxOnes;  // minimum swaps
    }
}
