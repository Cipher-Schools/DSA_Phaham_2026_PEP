package 05_Sliding_Window.Max_sum_of_subarray_of_size_k;

public class max_sum_subarray {
  
class Solution {

    // -------------------- Approach 1: Brute Force (Nested Loops) --------------------
    // TC: O(n * k), SC: O(1)
    public int maxSubarraySumBrute(int[] arr, int k) {
        int n = arr.length;
        int maxSum = Integer.MIN_VALUE;

        // Check all subarrays of size k
        for (int i = 0; i <= n - k; i++) {
            int currSum = 0;

            // Compute sum of current subarray
            for (int j = 0; j < k; j++) {
                currSum += arr[i + j];
            }

            maxSum = Math.max(maxSum, currSum);
        }

        return maxSum;
    }

    // -------------------- Approach 2: Sliding Window --------------------
    // TC: O(n), SC: O(1)
    public int maxSubarraySumSliding(int[] arr, int k) {
        int n = arr.length;
        if (n < k) return -1;

        int windowSum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int maxSum = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = Math.max(maxSum, windowSum);
        }

        return maxSum;
    }
}

