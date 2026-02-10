// GFG Problem - https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

// Approach - 1 | Linear Search | TC - O(n), SC - O(1)
int countFreq(vector<int> &arr, int target) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
      
      	// If the current element is equal to 
      	// target, increment the result
        if (arr[i] == target)
            res++;
    }
  
    return res;
}

// Approach - 2 | Binary Search | TC - O(log(n)), SC - O(1)
int binarySearch(vector<int> &nums, int target, bool findLast) {
    int start = 0, end = nums.size() - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            ans = mid;
            if (findLast) {
                start = mid + 1;   // move right for last occurrence
            } else {
                end = mid - 1;     // move left for first occurrence
            }
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}
int countFreq(vector<int> &arr, int target) {

    int left = binarySearch(arr, target, false);  // first position
    if (left == -1) return 0;                     // target not found

    int right = binarySearch(arr, target, true);  // last position
    return right - left + 1;
}

// Approach - 3 | Using Inbuilt Functions | TC - O(log(n)), SC - O(1)

int countFreq(vector<int> &arr, int target) {
    int l = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int r = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    return r - l;
}