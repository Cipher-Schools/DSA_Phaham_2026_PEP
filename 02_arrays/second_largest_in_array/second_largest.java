import java.util.*;

public class second_largest {

    // ================= Approach 1: Sorting =================
    // Time: O(n log n), Space: O(1) (ignoring sort stack)
    static int getSecondLargestSort(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);  // non-decreasing order

        // Traverse from second last element
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] != arr[n - 1]) {
                return arr[i];
            }
        }
        return -1; // No second largest (all elements equal)
    }


    // ================= Approach 2: Two Pass (No Sorting) =================
    // Time: O(n), Space: O(1)
    static int getSecondLargestTwoPass(int[] arr) {
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;

        // First pass: find largest
        for (int num : arr) {
            if (num > largest) {
                largest = num;
            }
        }

        // Second pass: find second largest
        for (int num : arr) {
            if (num > secondLargest && num != largest) {
                secondLargest = num;
            }
        }

        return (secondLargest == Integer.MIN_VALUE) ? -1 : secondLargest;
    }


    // ================= Approach 3: One Pass =================
    // Time: O(n), Space: O(1)
    static int getSecondLargestOnePass(int[] arr) {
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;

        for (int num : arr) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num < largest && num > secondLargest) {
                secondLargest = num;
            }
        }

        return (secondLargest == Integer.MIN_VALUE) ? -1 : secondLargest;
    }


    // ================= Main =================
    public static void main(String[] args) {
        int[] arr = {12, 35, 1, 10, 34, 1};

        System.out.println("Sort Method: " + getSecondLargestSort(arr.clone()));
        System.out.println("Two Pass Method: " + getSecondLargestTwoPass(arr));
        System.out.println("One Pass Method: " + getSecondLargestOnePass(arr));
    }
}
