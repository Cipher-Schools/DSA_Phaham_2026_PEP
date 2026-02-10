
// Iterative way -
int largest(vector<int>& arr) {
    int max = arr[0];

    //Traverse  from second and compare
    // every element with current max
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

// Recursive way - 
int findMax(vector<int>& arr, int i) {
  
   // Last index returns the element
    if (i == arr.size() - 1) {
        return arr[i];
    }

    // Find the maximum from the rest of the vector
    int recMax = findMax(arr, i + 1);

    // Compare with i-th element and return
    return max(recMax, arr[i]);
}

int largest(vector<int>& arr) {
  return findMax(arr,0);
}


// Using Inbuilt Function - 
int largest(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}