// LeetCode Problem 509 - https://leetcode.com/problems/fibonacci-number/
// TC - O(n), SC - O(1)

public class fibonacci {
  
 public int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
}