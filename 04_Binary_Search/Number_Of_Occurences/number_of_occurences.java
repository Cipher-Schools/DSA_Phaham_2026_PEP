package 04_Binary_Search.Number_Of_Occurences;

public class number_of_occurences {
      // -------------------- Approach 1: Linear Search --------------------
    // TC: O(n), SC: O(1)
    public int countFreqLinear(int[] arr, int target) {
        int res = 0;
        for (int num : arr) {
            if (num == target) {
                res++;
            }
        }
        return res;
    }

    // -------------------- Approach 2: Binary Search (First & Last) --------------------
    // TC: O(log n), SC: O(1)
    private int binarySearch(int[] nums, int target, boolean findLast) {
        int start = 0, end = nums.length - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans = mid;
                if (findLast) {
                    start = mid + 1;  // move right
                } else {
                    end = mid - 1;    // move left
                }
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    public int countFreqBinary(int[] arr, int target) {
        int left = binarySearch(arr, target, false);
        if (left == -1) return 0;

        int right = binarySearch(arr, target, true);
        return right - left + 1;
    }

    // -------------------- Approach 3: Lower Bound & Upper Bound --------------------
    // TC: O(log n), SC: O(1)
    private int lowerBound(int[] arr, int target) {
        int start = 0, end = arr.length;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }

    private int upperBound(int[] arr, int target) {
        int start = 0, end = arr.length;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }

    public int countFreqBounds(int[] arr, int target) {
        int l = lowerBound(arr, target);
        int r = upperBound(arr, target);
        return r - l;
    }
}
