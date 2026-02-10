// GFG Problem - https://www.geeksforgeeks.org/problems/reverse-a-string/1

class reverse_string {

    // ------------------ Approach 1: Iterative (create new string) ------------------
    // TC: O(n), SC: O(n)
    public String reverseStringIterative(String s) {
        StringBuilder res = new StringBuilder();

        // Traverse backward
        for (int i = s.length() - 1; i >= 0; i--) {
            res.append(s.charAt(i));
        }

        return res.toString();
    }

    // ------------------ Approach 2: Two Pointer (in-place using char array) ------------------
    // TC: O(n), SC: O(n) (because Java strings are immutable)
    public String reverseStringTwoPointer(String s) {
        char[] arr = s.toCharArray();
        int left = 0, right = arr.length - 1;

        while (left < right) {
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }

        return new String(arr);
    }

    // ------------------ Approach 3: In-built ------------------
    // TC: O(n), SC: O(n)
    public String reverseStringBuiltin(String s) {
        return new StringBuilder(s).reverse().toString();
    }
}
