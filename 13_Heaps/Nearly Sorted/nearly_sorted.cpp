// GFG Problem - https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

void nearlySorted(vector<int>& arr, int k) {
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>>pq;
    int idx = 0;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            arr[idx] = pq.top();
            pq.pop();
            idx++;
        }
    }
    while(!pq.empty()){
        arr[idx] = pq.top();
        pq.pop();
        idx++;
    }
}