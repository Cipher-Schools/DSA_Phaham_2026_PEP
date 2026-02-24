// LeetCode Problem 658 - https://leetcode.com/problems/find-k-closest-elements/

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    vector<int>ans;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<n;i++){
        if(pq.size()!=k){
            pq.push(arr[i]);
        }
        else{
            if(abs(arr[i]-x) < abs(x-pq.top())){
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans; 
}