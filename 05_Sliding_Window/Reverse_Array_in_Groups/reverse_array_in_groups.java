// GFG Problem - https://www.geeksforgeeks.org/problems/reverse-array-in-groups0255/1

// Window of size k | TC - O(n), SC - O(1)
public class reverse_array_in_groups {
  
   public void reverseInGroups(int[] arr, int k) {
        int n = arr.length;

        for (int i = 0; i < n; i += k) {
            int left = i;
            int right = Math.min(i + k - 1, n - 1); // handle last group

            while (left < right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
    }
}