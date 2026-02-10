import java.util.*;

public class Main {

    // ================= RECURSIVE WAY =================
    static boolean sorted(int[] arr, int index, int n) {
        if (n <= 1) return true;

        if (arr[index] > arr[index + 1])
            return false;

        return sorted(arr, index + 1, n - 1);
    }

    static boolean isSortedRecursive(int[] arr) {
        return sorted(arr, 0, arr.length);
    }


    // ================= ITERATIVE WAY =================
    static boolean isSortedIterative(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] > arr[i])
                return false;
        }
        return true;
    }


    // ================= USING INBUILT FUNCTION =================
    static boolean isSortedInbuilt(int[] arr) {
        // Java has no direct is_sorted, so compare with sorted copy
        int[] copy = arr.clone();
        Arrays.sort(copy);
        return Arrays.equals(arr, copy);
    }


    // ================= MAIN =================
    public static void main(String[] args) {

        int[] arr = {1, 2, 3, 4, 5};

        System.out.println("Recursive: " + isSortedRecursive(arr));
        System.out.println("Iterative: " + isSortedIterative(arr));
        System.out.println("Inbuilt: " + isSortedInbuilt(arr));
    }
}
