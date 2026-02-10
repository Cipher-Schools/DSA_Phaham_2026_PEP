public class FloorInSortedArray {

    // ------------------ Approach 1: Manual Binary Search ------------------
    static int findFloor(int[] arr, int x) {
        int ans = -1;
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > x) {
                high = mid - 1;
            } else {              // arr[mid] <= x
                ans = mid;        // potential floor
                low = mid + 1;    // search right for closer value
            }
        }
        return ans;
    }

    // ------------------ Approach 2: Using Library (Upper Bound Concept) ------------------
    static int findFloorUsingLibrary(int[] arr, int x) {
        int idx = Arrays.binarySearch(arr, x);

        // If exact match found
        if (idx >= 0) return idx;

        // If not found, binarySearch returns: -(insertion_point) - 1
        int insertionPoint = -idx - 1;

        // If insertion point is 0, no floor exists
        if (insertionPoint == 0) return -1;

        return insertionPoint - 1;
    }
}