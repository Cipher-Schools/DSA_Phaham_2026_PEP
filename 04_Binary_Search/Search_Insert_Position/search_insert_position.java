// LeetCode Problem 35 - https://leetcode.com/problems/search-insert-position/
// TC - O(log(n)), SC - O(1)

private int search(int[] nums, int start, int end, int target) {
        if (start > end) return start;  // insertion position

        int mid = start + (end - start) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target)
            return search(nums, mid + 1, end, target);
        else
            return search(nums, start, mid - 1, target);
    }

    public int searchInsert(int[] nums, int target) {
        return search(nums, 0, nums.length - 1, target);
    }
}