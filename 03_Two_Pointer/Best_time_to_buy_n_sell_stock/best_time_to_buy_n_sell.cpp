// LeetCode_Problem 121 - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int max_profit = 0, profit = 0, buy = 0;
    for(int i=1;i<n;i++){
        if(prices[i]<prices[buy]){
            buy = i;
        }
        if(prices[i]>prices[buy]){
            profit = prices[i] - prices[buy];
        }
        if(profit > max_profit){
            max_profit = profit;
        }
    }
    return max_profit;
}