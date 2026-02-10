// 

// Approach - 1 | Using HashSet | TC - O(n), SC - O(n)

bool pairInSortedRotated(vector<int> &arr, int target){
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++){

        // Calculate the complement that added to
        // arr[i], equals the target
        int complement = target - arr[i];

        // Check if the complement exists in the set
        if (s.find(complement) != s.end())
            return true;

        // Add the current element to the set
        s.insert(arr[i]);
    }
  
    // If no pair is found
    return false;
}

// Approach - 2 | Two Pointer | TC - O(n), SC - O(1)
bool pairInSortedRotated(vector<int>& arr, int target) {
    int n = arr.size();

    // Find the pivot element
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            break;
	
    // l is now index of smallest element
    int l = (i + 1) % n;

    // r is now index of largest element
    int r = i;

    // Keep moving either l or r till they meet
    while (l != r) {

        // If we find a pair with sum target, return true
        if (arr[l] + arr[r] == target)
            return true;

        // If current pair sum is less, move to higher sum
        if (arr[l] + arr[r] < target)
            l = (l + 1) % n;

        // Move to lower sum
        else
            r = (r - 1 + n) % n;
    }
    return false;
}
