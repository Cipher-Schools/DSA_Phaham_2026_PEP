public class remove_duplicates_from_sorted_array {

    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;

        int j = 0;  // last unique element index

        for (int i = 1; i < nums.length; i++) {
            if (nums[j] != nums[i]) {
                nums[++j] = nums[i];
            }
        }
        return j + 1;  // length of unique elements
    }

    // Counting duplicates
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int count = 0;  // number of duplicates found

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                nums[i - count] = nums[i];
            }
        }
        return n - count;  // new length
    }
}
