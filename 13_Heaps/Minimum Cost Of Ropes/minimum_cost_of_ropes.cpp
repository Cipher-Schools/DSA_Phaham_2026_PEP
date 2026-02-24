// GFG Problem - https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

int minCost(vector<int>& arr) {
    // code here
    // connect the two shortest ropes first, minimizing the cost at each step
    int n = arr.size();
    //min heap 
    priority_queue<int , vector<int> , greater<int>> pq ;
    
    for(int i=0;i<n;i++) pq.push(arr[i]);
    
    int cost= 0;
    
    while(pq.size()>1)
    {
        int firstRope = pq.top();
        pq.pop();
        int secondRope = pq.top();
        pq.pop();

        cost += firstRope + secondRope;
        pq.push(firstRope + secondRope);
    }
    
    return cost;
}