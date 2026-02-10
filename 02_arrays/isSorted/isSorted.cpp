#include <iostream>
using namespace std;

// Recursive way - 
bool sorted(vector<int>& arr, int n){
    if(n<=1)return true;
    if(arr[0] > arr[1]) return false;
    return sorted(arr +1, n-1);
} 
bool isSorted(vector<int>& arr) {
    // code here
    int n = arr.size();
    return sorted(arr, n);
}

// Iterative way - 
bool isSorted(vector<int>& arr) {
    
    // Iterate over the array and check if 
    // every element is greater than or
    // equal to previous element.
    for (int i = 1; i < arr.size(); i++)
        if (arr[i - 1] > arr[i])
            return false;

    return true;
}

// Using Inbuilt function 
bool isSorted(vector<int> &arr){
    
    if(is_sorted(arr.begin(), arr.end()))
    return true;
    
    return false;
}