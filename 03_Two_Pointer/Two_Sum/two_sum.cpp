// GFG Problem - https://www.geeksforgeeks.org/problems/key-pair5616/1

// Approach - 1 | Brute Force | Use Nested Loops | TC - O(n^2) | SC - O(1)
bool twoSum(vector<int> &arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
      
        // For each element arr[i], check every
        // other element arr[j] that comes after it
        for (int j = i + 1; j < n; j++) {
          
            // Check if the sum of the current pair
            // equals the target
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
  
    // If no pair is found after checking
    // all possibilities
    return false;
}

// Approach - 2 | Sorting then Binary Search | TC - O(nlog(n)) | SC - O(1)
bool binarySearch(vector<int> &arr, int left, int right, int target){
    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool twoSum(vector<int> &arr, int target){
    
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];
        if (binarySearch(arr, i + 1, arr.size() - 1, complement))
            return true;
    }
  
    // If no pair is found
    return false;
}


// Approach - 3 | Sorting and Two Pointer | TC - O(nlog(n)) | SC - O(1)
bool twoSum(vector<int> &arr, int target){
  
    sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;

    while (left < right){
        int sum = arr[left] + arr[right];
        if (sum == target)
            return true;
        else if (sum < target)
            left++; 
        else
            right--;
    }
    return false;
}

// Approach - 4 | Using Hashset/Hashmap | TC - O(n), SC - (n)
bool twoSum(vector<int> &arr, int target){
  
    // Create an unordered_set to store the elements
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
    return false;
}