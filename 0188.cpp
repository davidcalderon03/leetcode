class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<pair<int, int>> transactions(k);
        for (int i = 0; i < k; ++i) {
            transactions[i] = make_pair(INT_MIN, 0);
        }
        for (int x : prices) {
            transactions[0].first = max(transactions[0].first, -x);
            transactions[0].second = max(transactions[0].second, x + transactions[0].first);
            for (int i = 1; i < transactions.size(); ++i) {
                transactions[i].first = max(transactions[i].first, transactions[i - 1].second - x);
                transactions[i].second = max(transactions[i].second, x + transactions[i].first);
            }
        }
        return transactions[k - 1].second;
    }
};
