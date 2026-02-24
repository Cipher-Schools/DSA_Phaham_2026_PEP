// GFG Problem - https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

// Optimal APPROACH - Using Min Heap

vector<int> kLargest(vector<int>& arr, int k) {
    // Your code here
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Another Approach - Using Max Heap
vector<int> kLargest(vector<int>& arr, int k) {
    priority_queue<int> pq(arr.begin(), arr.end());
    vector<int> ans;
    for(int i = 0; i < k; i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
