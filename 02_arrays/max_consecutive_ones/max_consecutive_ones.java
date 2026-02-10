public class max_consecutive_ones {

    static int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;
        int maxCount = 0;

        for (int num : nums) {
            if (num == 1) {
                count++;
            } else {
                count = 0;
            }
            maxCount = Math.max(maxCount, count);
        }

        return maxCount;
    }

    // Test
    public static void main(String[] args) {
        int[] nums = {1, 1, 0, 1, 1, 1};
        System.out.println(findMaxConsecutiveOnes(nums));  // Output: 3
    }
}
