// GFG Problem - https://www.geeksforgeeks.org/problems/factorial5739/1
// Approach - 1 | Iterative  | TC - O(n), SC - O(1)

public class factorial {
  
    // ------------------ Approach 1: Iterative ------------------
    // TC: O(n), SC: O(1)
    public int factorialIterative(int n) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            ans *= i;
        }
        return ans;
    }

    // ------------------ Approach 2: Recursive ------------------
    // TC: O(n), SC: O(n) recursion stack
    public int factorialRecursive(int n) {
        if (n == 0 || n == 1) return 1;
        return n * factorialRecursive(n - 1);
    }
}
