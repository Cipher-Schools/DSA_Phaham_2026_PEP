import java.util.*;

public class reverse_an_array {

    // ================= Approach 1: Half traversal swap =================
    static void reverseArrayHalfSwap(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
    }


    // ================= Approach 2: Two Pointer =================
    static void reverseArrayTwoPointer(int[] arr) {
        int start = 0;
        int end = arr.length - 1;

        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    // ================= Recursive Way =================
    static void reverseArrRecursive(int[] arr, int start, int end) {
        if (start >= end) return;

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        reverseArrRecursive(arr, start + 1, end - 1);
    }

    static void reverseArrayRecursive(int[] arr) {
        reverseArrRecursive(arr, 0, arr.length - 1);
    }


    // ================= Main for testing =================
    public static void main(String[] args) {

        int[] original = {1, 2, 3, 4, 5};

        int[] a1 = original.clone();
        reverseArrayHalfSwap(a1);
        System.out.println("Half Swap: " + Arrays.toString(a1));

        int[] a2 = original.clone();
        reverseArrayTwoPointer(a2);
        System.out.println("Two Pointer: " + Arrays.toString(a2));

        int[] a3 = original.clone();
        reverseArrayRecursive(a3);
        System.out.println("Recursive: " + Arrays.toString(a3));
    }
}
