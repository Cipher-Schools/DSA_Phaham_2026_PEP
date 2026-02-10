public class triplet_sum_in_array {

    // ================= Approach 1: Brute Force =================
    // TC: O(n^3), SC: O(1)
    static boolean hasTripletSumBrute(int[] arr, int target) {
        int n = arr.length;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == target) {
                        return true;
                    }
                }
            }
        }
        return false;
    }


    // ================= Approach 2: HashSet =================
    // TC: O(n^2), SC: O(n)
    static boolean hasTripletSumHash(int[] arr, int target) {
        int n = arr.length;

        for (int i = 0; i < n - 2; i++) {

            HashSet<Integer> set = new HashSet<>();

            for (int j = i + 1; j < n; j++) {
                int second = target - arr[i] - arr[j];

                if (set.contains(second)) {
                    return true;
                }

                set.add(arr[j]);
            }
        }
        return false;
    }


    // ================= Approach 3: Sorting + Two Pointer =================
    // TC: O(n^2), SC: O(1)
    static boolean hasTripletSumTwoPointer(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            int requiredSum = target - arr[i];

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum == requiredSum) {
                    return true;
                } else if (sum < requiredSum) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return false;
    }


    // ================= Main (Testing) =================
    public static void main(String[] args) {
        int[] arr = {1, 4, 45, 6, 10, 8};
        int target = 22;

        System.out.println("Brute Force: " + hasTripletSumBrute(arr.clone(), target));
        System.out.println("HashSet: " + hasTripletSumHash(arr.clone(), target));
        System.out.println("Two Pointer: " + hasTripletSumTwoPointer(arr.clone(), target));
    }
}
