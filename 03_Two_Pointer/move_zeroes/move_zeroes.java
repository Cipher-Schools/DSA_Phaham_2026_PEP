public class move_zeroes {

    static void moveZeroes(int[] nums) {
        int insertPos = 0;

        // Place all non-zero elements at the beginning
        for (int num : nums) {
            if (num != 0) {
                nums[insertPos++] = num;
            }
        }

        // Fill remaining positions with zeros
        while (insertPos < nums.length) {
            nums[insertPos++] = 0;
        }
    }

    // Test
    public static void main(String[] args) {
        int[] nums = {0, 1, 0, 3, 12};
        moveZeroes(nums);

        for (int num : nums) {
            System.out.print(num + " ");
        }
        // Output: 1 3 12 0 0
    }
}
