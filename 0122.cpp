class Solution {
public:
  unordered_map<int, int> cache;
  int hash(int index, bool holding) { return index << 1 | holding; }
  int maxProfit(vector<int> &prices) { return helper(prices, 0, 0); }

  int helper(vector<int> &prices, int index, bool holding) {
    if (index >= prices.size()) {
      return 0;
    }
    if (cache.contains(hash(index, holding))) {
      return cache[hash(index, holding)];
    }
    int doNothing = helper(prices, index + 1, holding);
    if (holding == 0) { // Nothing bought -> need to buy
      cache[hash(index, holding)] =
          std::max(doNothing, helper(prices, index + 1, true) - prices[index]);
    } else { // Holding stock -> need to sell
      cache[hash(index, holding)] =
          std::max(doNothing, helper(prices, index + 1, false) + prices[index]);
    }
    return cache[hash(index, holding)];
  }
};
