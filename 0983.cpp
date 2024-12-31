class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<int> minCosts(days.size() + 1, 0);
    for (int i = 0; i < days.size(); ++i) {
      int option1 = minCosts[i] + costs[0];
      int j;
      for (j = i; j >= 0 && days[j] > days[i] - 7; --j) {
      }
      int option2 = minCosts[j + 1] + costs[1];
      for (; j >= 0 && days[j] > days[i] - 30; --j) {
      }
      int option3 = minCosts[j + 1] + costs[2];
      minCosts[i + 1] = min(option1, min(option2, option3));
    }
    return minCosts.back();
  }
};
