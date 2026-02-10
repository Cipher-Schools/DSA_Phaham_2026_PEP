// GFG Problem - https://www.geeksforgeeks.org/problems/factorial5739/1

// Approach - 1 | Iterative  | TC - O(n), SC - O(1)
int factorial(int n) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            // calculating the factorial
            ans = ans * i;
        }
        return ans;
  }


// Approach - 2 | Recursive way
int factorial(int n)
{

    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
