// GFG Problem - https://www.geeksforgeeks.org/problems/reverse-array-in-groups0255/1

// Window of size k | TC - O(n), SC - O(1)

void reverseInGroups(vector<int>& arr, int k){
    
    // Get the size of the array
    int n = arr.size();  

    for (int i = 0; i < n; i += k) {
        int left = i;

        // to handle case when k is not multiple of n
        int right = min(i + k - 1, n - 1);

        // reverse the sub-array [left, right]
        while (left < right)  {
            swap(arr[left++], arr[right--]);
        }
    }
}
