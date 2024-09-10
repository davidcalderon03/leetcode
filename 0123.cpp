class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MIN, secondBuy = INT_MIN;
        int firstSell = 0, secondSell = 0;
        for (int x : prices) {
            firstBuy = max(firstBuy, -x);
            firstSell = max(firstSell, x + firstBuy);
            secondBuy = max(secondBuy, firstSell - x);
            secondSell = max(secondSell, x + secondBuy);
        }
        return secondSell;
    }

    // Complex solution 
    // int maxProfit(vector<int>& prices) {
    //     map<pair<int, int>, int> dp;
    //     helper(prices, 0, 0, 0, 0, dp);
    //     int l = prices.size() - 1;
    //     int maximum = 0;
    //     for (int i = 0; i < 5; i+=2) {
    //         maximum = max(dp[make_pair(l, i)], maximum);
    //     }
    //     return maximum;
    // }

    // void helper(vector<int>& prices, int index, int transactionsMade, int stocksHeld, int moneyHeld, map<pair<int, int>, int>& dp) {
    //     pair<int, int> key = make_pair(index, transactionsMade);
    //     pair<int, int> key2 = make_pair(index, transactionsMade + 1);
    //     if ((transactionsMade % 2 == 0 && dp.contains(key) && dp[key] > moneyHeld) ||
    //        (transactionsMade % 2 == 1 && dp.contains(key2) && dp[key2] > moneyHeld + (prices[index] - stocksHeld))
    //        ) return;
        
    //     if (transactionsMade % 2 == 0) {
    //         dp[key] = moneyHeld;
    //     } else {
    //         dp[key2] = moneyHeld + (prices[index] - stocksHeld);
    //     }

    //     for (int i = index + 1; i < prices.size(); ++i) {
    //         if (transactionsMade < 4 && transactionsMade % 2 == 0) { // Buy
    //             helper(prices, i, transactionsMade + 1, stocksHeld + prices[index], moneyHeld, dp);
    //         } else if (transactionsMade < 4 && transactionsMade % 2 == 1) { // Sell
    //             helper(prices, i, transactionsMade + 1, 0, moneyHeld + (prices[index]-stocksHeld), dp);
    //         }
    //         helper(prices, i, transactionsMade, stocksHeld, moneyHeld, dp); // Do nothing
    //     }
    // }
};
