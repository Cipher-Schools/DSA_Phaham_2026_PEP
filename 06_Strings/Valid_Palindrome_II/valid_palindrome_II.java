// LeetCode Problem 680 - https://leetcode.com/problems/valid-palindrome-ii/submissions/1905210934/
// TC - O(n), SC - O(1)

public class valid_palindrome_II {
  
    private boolean isPal(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }

    // Main function
    public boolean validPalindrome(String s) {
        int start = 0, end = s.length() - 1;

        while (start < end) {
            if (s.charAt(start) != s.charAt(end)) {
                // Skip either left or right character once
                return isPal(s, start + 1, end) || isPal(s, start, end - 1);
            }
            start++;
            end--;
        }
        return true;
    }
}
