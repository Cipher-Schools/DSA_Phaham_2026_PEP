// Leetcode Problem 125 - https://leetcode.com/problems/valid-palindrome/description/
// TC - O(n), SC - O(1)

public class valid_palindrome {
  
    public boolean isPalindrome(String s) {
        int start = 0, end = s.length() - 1;

        while (start <= end) {

            // Skip non-alphanumeric characters
            while (start < end && !Character.isLetterOrDigit(s.charAt(start))) {
                start++;
            }
            while (start < end && !Character.isLetterOrDigit(s.charAt(end))) {
                end--;
            }

            // Compare ignoring case
            if (Character.toLowerCase(s.charAt(start)) != 
                Character.toLowerCase(s.charAt(end))) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
