// GFG Problem - https://www.geeksforgeeks.org/problems/pair-sum-in-a-sorted-and-rotated-array/1

public class pair_sum_in_sorted_rotated_array {

  // Approach - 1 | Using HashSet | TC - O(n), SC - O(n)

   static boolean pairInSortedRotatedHash(int[] arr, int target) {
        HashSet<Integer> set = new HashSet<>();

        for (int num : arr) {
            int complement = target - num;

            if (set.contains(complement)) {
                return true;
            }

            set.add(num);
        }
        return false;
    }
    
    // Approach - 2 | Two Pointer | TC - O(n), SC - O(1)

       static boolean pairInSortedRotatedTwoPointer(int[] arr, int target) {
        int n = arr.length;

        // Step 1: Find pivot (largest element index)
        int i;
        for (i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                break;
            }
        }

        int left = (i + 1) % n;  // index of smallest element
        int right = i;           // index of largest element

        // Step 2: Two-pointer traversal in circular manner
        while (left != right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                return true;
            } else if (sum < target) {
                left = (left + 1) % n;   // move forward
            } else {
                right = (right - 1 + n) % n; // move backward
            }
        }

        return false;
    }
}
