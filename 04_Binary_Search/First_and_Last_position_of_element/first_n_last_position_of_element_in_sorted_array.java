public class first_n_last_position_of_element_in_sorted_array {
      private int binarySearch(int[] nums, int target, boolean findLast) {
        int start = 0, end = nums.length - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans = mid;
                if (findLast) {
                    start = mid + 1;   // move right for last occurrence
                } else {
                    end = mid - 1;     // move left for first occurrence
                }
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    public int[] searchRange(int[] nums, int target) {
        int left = binarySearch(nums, target, false);  // first position
        int right = binarySearch(nums, target, true);  // last position
        return new int[]{left, right};
    }
}
