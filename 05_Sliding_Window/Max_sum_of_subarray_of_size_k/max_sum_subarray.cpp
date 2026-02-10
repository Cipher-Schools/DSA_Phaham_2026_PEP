// GFG Problem - https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

// Approach - 1 | Nested Loops | TC - O(n*k), SC - O(1)
int maxSubarraySum(vector<int>& arr, int k) {
    int n = arr.size();
    int maxSum = 0;

    // check all subarrays of size k
    for (int i = 0; i <= n - k; i++) {
        int currSum = 0;

        // compute sum of current subarray
        for (int j = 0; j < k; j++) {
            currSum += arr[i + j];
        }

        // update maximum sum
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

// Approach - 2 | sliding window (fixed size of k) | TC - , SC - 
