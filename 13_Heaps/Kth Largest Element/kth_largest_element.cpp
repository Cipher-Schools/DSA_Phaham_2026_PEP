// LeetCode Problem 215 - https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1923614830/

// Optimal Approach - Using Min-Heap
int findKthLargest(vector<int>& nums, int k) {
    // Min heap to keep the largest k elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {

        // Push current number into min heap
        minHeap.push(num);

        // If heap size exceeds k, remove smallest
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Now the top of the min heap is the kth largest
    return minHeap.top();
}

// Another Approach - Using Max-Heap
int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int>pq(nums.begin(), nums.end());
    for(int i=0;i<k-1;i++){
        pq.pop();
    }
    // get kth largest
    return pq.top();
}