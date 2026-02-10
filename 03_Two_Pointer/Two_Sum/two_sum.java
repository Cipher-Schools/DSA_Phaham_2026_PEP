package 03_Two_Pointer.Two_Sum;

public class two_sum {

    // ================= Approach 1: Brute Force =================
    // TC: O(n^2), SC: O(1)
    static boolean twoSumBrute(int[] arr, int target) {
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == target) {
                    return true;
                }
            }
        }
        return false;
    }


    // ================= Approach 2: Sorting + Binary Search =================
    // TC: O(n log n), SC: O(1)
    static boolean binarySearch(int[] arr, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
                return true;
            else if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    static boolean twoSumBinarySearch(int[] arr, int target) {
        Arrays.sort(arr);

        for (int i = 0; i < arr.length; i++) {
            int complement = target - arr[i];
            if (binarySearch(arr, i + 1, arr.length - 1, complement))
                return true;
        }
        return false;
    }


    // ================= Approach 3: Sorting + Two Pointer =================
    // TC: O(n log n), SC: O(1)
    static boolean twoSumTwoPointer(int[] arr, int target) {
        Arrays.sort(arr);

        int left = 0, right = arr.length - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target)
                return true;
            else if (sum < target)
                left++;
            else
                right--;
        }
        return false;
    }


    // ================= Approach 4: HashSet =================
    // TC: O(n), SC: O(n)
    static boolean twoSumHash(int[] arr, int target) {
        HashSet<Integer> set = new HashSet<>();

        for (int num : arr) {
            int complement = target - num;

            if (set.contains(complement))
                return true;

            set.add(num);
        }
        return false;
    }


    // ================= Main (Testing) =================
    public static void main(String[] args) {
        int[] arr = {1, 4, 45, 6, 10, 8};
        int target = 16;

        System.out.println("Brute Force: " + twoSumBrute(arr.clone(), target));
        System.out.println("Binary Search: " + twoSumBinarySearch(arr.clone(), target));
        System.out.println("Two Pointer: " + twoSumTwoPointer(arr.clone(), target));
        System.out.println("HashSet: " + twoSumHash(arr.clone(), target));
    }
}
