public class best_time_to_buy_n_sell {

    static int maxProfit(int[] prices) {
        int n = prices.length;
        int maxProfit = 0;
        int profit;
        int buy = 0;  // index of minimum price so far

        for (int i = 1; i < n; i++) {

            // Update buying day if a lower price is found
            if (prices[i] < prices[buy]) {
                buy = i;
            }

            // Calculate profit if selling today
            if (prices[i] > prices[buy]) {
                profit = prices[i] - prices[buy];

                // Update max profit
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }

    // Test
    public static void main(String[] args) {
        int[] prices = {7, 1, 5, 3, 6, 4};
        System.out.println(maxProfit(prices));  // Output: 5
    }
}

