import java.util.*;

public class Main {

    // ================= ITERATIVE WAY =================
    static int largestIterative(int[] arr) {
        int max = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }


    // ================= RECURSIVE WAY =================
    static int findMax(int[] arr, int i) {
        // Base case: last index
        if (i == arr.length - 1) {
            return arr[i];
        }

        int recMax = findMax(arr, i + 1);

        return Math.max(recMax, arr[i]);
    }

    static int largestRecursive(int[] arr) {
        return findMax(arr, 0);
    }


    // ================= USING INBUILT FUNCTION =================
    static int largestInbuilt(int[] arr) {
        // Java 8+ Streams
        return Arrays.stream(arr).max().getAsInt();
    }


    // ================= MAIN =================
    public static void main(String[] args) {
        int[] arr = {3, 9, 2, 15, 6};

        System.out.println("Iterative Max: " + largestIterative(arr));
        System.out.println("Recursive Max: " + largestRecursive(arr));
        System.out.println("Inbuilt Max: " + largestInbuilt(arr));
    }
}
