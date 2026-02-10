// GFG Problem - https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// Approach - 1 | Brute Force | 3 Nested Loops | TC - O(n^3), SC - O(1)
bool hasTripletSum(vector<int>& arr, int target) {
  int n = arr.size();
  
  // Fix the first element as arr[i] 
  for (int i = 0; i < n - 2; i++) {
    
    // Fix the second element as arr[j] 
    for (int j = i + 1; j < n - 1; j++) {
      
      // Now look for the third number 
      for (int k = j + 1; k < n; k++) { 
        if (arr[i] + arr[j] + arr[k] == target)
        return true; 
      } 
    } 
  } 
  
  return false; 
} 

// Approach - 2 | HashSet | TC - O(n^2), SC - O(n)
bool hasTripletSum(vector<int>& arr, int target) {
  int n = arr.size();
  
  // Fix the first element as arr[i] 
  for (int i = 0; i < n - 2; i++) {
    
    // Hash set to store potential second elements
    unordered_set<int> st;
    
    // Fix the third element as arr[j]
    for(int j = i + 1; j < n; j++) {
      int second = target - arr[i] - arr[j];
      
      // Search for second element in hash set
      if(st.find(second) != st.end()) {
        return true;
      }
      
      // Add arr[j] as a potential second element
      st.insert(arr[j]);
    }
  } 
  
  return false;
} 

// Approach - 3 | Sorting and Two Pointer | TC - O(n^2), SC - O(n)
bool hasTripletSum(vector<int>& arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
      
        int requiredSum = target - arr[i];
        while(l < r) {
            if(arr[l] + arr[r] == requiredSum)
                return true;
            if(arr[l] + arr[r] < requiredSum)
                l++;
            else if(arr[l] + arr[r] > requiredSum)
                r--;
        }
    } 

    return false; 
} 