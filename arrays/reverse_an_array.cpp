// Problem - https://www.geeksforgeeks.org/problems/reverse-an-array/0

// Solution
// Approach - 1
void reverseArray(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n/2; i++) {
    	swap(arr[i], arr[n - i - 1]);
    }
}

// Approach - 2 | Two Pointer

void reverseArray(vector<int> &arr) {
      int start = 0;
      int end = arr.size() - 1;

      while (start < end) {
          swap(arr[start], arr[end]);
          start++;
          end--;
      }
}

// Inbuilt - 
void reverseArray(vector<int> &arr){
 reverse(arr.begin(), arr.end());
}

// Recursive Way
void reverseArr(vector<int> &arr,int start, int end){
    if(start>=end) return;
    swap(arr[start], arr[end]);
    reverseArr(arr, start+1, end-1);
}
void reverseArray(vector<int> &arr) {
    // code here
    int n = arr.size();
    int start = 0, end = n-1;
    return reverseArr(arr, start, end);
}