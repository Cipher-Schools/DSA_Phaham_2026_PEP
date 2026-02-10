package arrays.merge_sorted_arrays;

public import java.util.Arrays;

public class Main {

    // ---------------- Demo: merge two fixed arrays into a third (like your first C++ snippet) ----------------
    public static void demoMergeFixedArrays() {
        int[] arr1 = {2, 5, 7, 8, 10};
        int[] arr2 = {1, 4, 6, 9, 11};
        int[] arr3 = new int[arr1.length + arr2.length];

        int i = 0, j = 0, k = 0;
        // Merge while both arrays have elements
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] <= arr2[j]) {
                arr3[k++] = arr1[i++];
            } else {
                arr3[k++] = arr2[j++];
            }
        }
        // Copy remaining elements from arr1
        while (i < arr1.length) {
            arr3[k++] = arr1[i++];
        }
        // Copy remaining elements from arr2
        while (j < arr2.length) {
            arr3[k++] = arr2[j++];
        }

        // Print merged array
        System.out.print("Merged array (fixed demo): ");
        for (int val : arr3) System.out.print(val + " ");
        System.out.println();
    }


    // ---------------- LeetCode 88 - Approach 1: Using extra array ----------------
    // O(m + n) time, O(m + n) extra space
    public static void mergeWithExtraArray(int[] nums1, int m, int[] nums2, int n) {
        int[] res = new int[m + n];
        int i = 0, j = 0, k = 0;

        // Merge first m elements of nums1 and all of nums2 into res
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                res[k++] = nums1[i++];
            } else {
                res[k++] = nums2[j++];
            }
        }

        // Copy remaining part
        while (i < m) res[k++] = nums1[i++];
        while (j < n) res[k++] = nums2[j++];

        // Copy merged result back into nums1 (nums1 has length m+n)
        System.arraycopy(res, 0, nums1, 0, m + n);
    }


    // ---------------- LeetCode 88 - Approach 2: In-place from the end ----------------
    // O(m + n) time, O(1) extra space
    public static void mergeInPlaceFromEnd(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;           // pointer for last valid element in nums1
        int j = n - 1;           // pointer for last element in nums2
        int k = m + n - 1;       // pointer for last position in nums1 (full length)

        // Fill nums1 from the back choosing the larger between nums1[i] and nums2[j]
        while (j >= 0) { // run until all nums2 elements are placed
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }


    // ---------------- LeetCode 88 - Approach 3: Swap-then-sort method ----------------
    // swap larger nums1 tail with smaller nums2 head, sort parts, then copy
    public static void mergeSwapThenSort(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;
        int j = 0;

        // Swap elements so that the first m of nums1 are <= last n of nums1 after sorting steps
        while (i >= 0 && j < n) {
            if (nums1[i] > nums2[j]) {
                // swap
                int tmp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = tmp;
                i--;
                j++;
            } else {
                break; // if nums1[i] <= nums2[j], earlier elements are also <=
            }
        }

        // Sort the first m part of nums1 and entire nums2
        Arrays.sort(nums1, 0, m); // sort exclusive end index
        Arrays.sort(nums2);       // sort all of nums2

        // Copy sorted nums2 into the tail of nums1
        for (int k = 0; k < n; k++) {
            nums1[m + k] = nums2[k];
        }
    }


    // ---------------- main: demo usage ----------------
    public static void main(String[] args) {
        demoMergeFixedArrays();

        // Prepare arrays for LeetCode-style demos
        int[] a1 = {1, 2, 3, 0, 0, 0};    // length m+n; first m are valid
        int[] b1 = {2, 5, 6};
        int m = 3, n = 3;

        // Approach 1 demo
        int[] copy1 = a1.clone();
        mergeWithExtraArray(copy1, m, b1, n);
        System.out.println("After mergeWithExtraArray: " + Arrays.toString(copy1));

        // Approach 2 demo
        int[] copy2 = a1.clone();
        mergeInPlaceFromEnd(copy2, m, b1, n);
        System.out.println("After mergeInPlaceFromEnd: " + Arrays.toString(copy2));

        // Approach 3 demo
        int[] a3 = {1, 2, 3, 0, 0, 0};
        int[] b3 = {2, 5, 6};
        int[] copy3 = a3.clone();
        mergeSwapThenSort(copy3, m, b3, n);
        System.out.println("After mergeSwapThenSort: " + Arrays.toString(copy3));
    }
}
