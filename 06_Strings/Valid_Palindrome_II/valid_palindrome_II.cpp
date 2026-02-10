// LeetCode Problem 680 - https://leetcode.com/problems/valid-palindrome-ii/submissions/1905210934/
// TC - O(n), SC - O(1)

bool isp(string s, int l, int r) {
        for (int i = l, j = r; i < j; i++, j--)
            if (s[i] != s[j]) return false;
        return true;
    }
    bool validPalindrome(string s) {
        // for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        //     if (s[i] != s[j]) return isp(s, i + 1, j) || isp(s, i, j - 1);
        // return true;
        int start  = 0, end = s.size()-1;
        while(start <= end){
            if (s[start] != s[end]) return isp(s, start + 1, end) || isp(s, start, end - 1);
            start++;
            end--;
        }
        return true;
    }