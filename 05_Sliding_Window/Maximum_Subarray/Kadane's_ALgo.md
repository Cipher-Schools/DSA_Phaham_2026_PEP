Kadane’s Algorithm
So, how does this work?
The idea is simple. It works by iterating through the array once while maintaining two values: the current sum of the subarray being considered and the maximum sum found so far. As we go through the array, we keep adding each element to the current sum. If the current subarray sum becomes negative, we will restart from the current element. The maximum sum is updated whenever the current sum exceeds it. By the end of the loop, the algorithm returns the largest sum of any contiguous subarray, and it does so in linear time, O(n), making it much faster than brute-force methods.

Code:
```
class Solution {
    public int maxSubArray(int[] nums) {
        return kadaneAlgo(nums);
    }

    private int kadaneAlgo(int[] nums) {
        int maxx = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum = Math.max(sum + nums[i], nums[i]);
            maxx = Math.max(maxx, sum);  
        }

        return maxx;
    }
}
```
Step 1: Initialization

```
int maxx = nums[0];
int sum = nums[0];
```
maxx: This variable stores the largest sum encountered during the traversal of the array. It is initialized to nums[0] (the first element in the array).
sum: This variable keeps track of the sum of the current subarray being considered. It is also initialized to nums[0] to start with the first element.

Step 2: Loop through the Array
```
for (int i = 1; i < nums.length; i++) {
```
The loop starts at index 1 (the second element) because we’ve already initialized maxx and sum to the first element.

Step 3: Update sum
```
sum = Math.max(sum + nums[i], nums[i]);
sum + nums[i]: This represents adding the current element nums[i] to the sum of the previous subarray. If the sum is positive, it 
```
would be beneficial to include this element in the subarray.
nums[i]: This represents starting a new subarray with just the current element, effectively resetting the sum if continuing the current subarray results in a negative sum.

```
Math.max(sum + nums[i], nums[i]): This ensures that we either extend the current subarray or start fresh from the current element. If the sum of the current subarray becomes negative, we start a new subarray starting at nums[i].
```

Step 4: Update maxx
```
maxx = Math.max(maxx, sum);
```
After updating sum, this line updates maxx to be the maximum of the current maxx (the largest sum found so far) and the new sum. This ensures that maxx always holds the largest sum of any subarray encountered up to that point.

Step 5: Return the Result
```
return maxx;
```
After the loop finishes iterating through the entire array, maxx holds the maximum sum of any contiguous subarray, which is then returned as the result.
This implementation of Kadane’s algorithm works in linear time O(n) and efficiently finds the largest sum of any contiguous subarray.