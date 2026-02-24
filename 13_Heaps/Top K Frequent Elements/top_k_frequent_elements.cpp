// LeetCode Problem 347 - https://leetcode.com/problems/top-k-frequent-elements/description/

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int>mp;
    for(int num:nums){
        mp[num]++;
    }
    // take max-heap
    priority_queue<pair<int, int>>pq;
    for(auto [a, b]:mp){
        pq.push({b, a});
    }
    // get top k
    vector<int>ans;
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}