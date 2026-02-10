/*
Time complexity: O(logn) - Since binary search reduces the search space by half at each step, 
the maximum number of iterations required to find the target is log base 2 of n, where n is the size of the array. 
Therefore, the time complexity of binary search is O(logn).

Space complexity: O(1) - Binary search only uses a constant amount of additional space for the two pointers and the 
middle index variable, so the space complexity is O(1).

*/
public class binary_search {
      public int search(int[] nums, int target) {
        int left = 0; // initialize left pointer to 0
        int right = nums.length - 1; // initialize right pointer to the last index of the array
        
        while (left <= right) { // continue the loop till left pointer is less than or equal to right pointer
            int mid = left + (right - left) / 2; // calculate the middle index of the array
            
            if (nums[mid] == target) { // check if the middle element is equal to target
                return mid; // return the middle index
            } else if (nums[mid] < target) { // check if the middle element is less than target
                left = mid + 1; // move the left pointer to the right of middle element
            } else { // if the middle element is greater than target
                right = mid - 1; // move the right pointer to the left of middle element
            }
        }
        
        return -1; // target not found in the array
    }  
}
