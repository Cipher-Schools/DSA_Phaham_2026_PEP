// GFG Problem - https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
// TC - O(log(n)), SC - O(1)

int findFloor(vector<int> &arr, int x)
{
    // Your code here
    int ans = -1;
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else if (arr[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

// Approach - 2 | Using Library method | TC - O(logn), SC - O(1)

int findFloor(vector<int>& arr, int x) {
    auto itr = upper_bound(arr.begin(), arr.end(), x); 
    if (itr == arr.begin()) 
        return -1; 
    itr--; 
    return itr - arr.begin();
}
