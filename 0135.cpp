class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> candies(ratings.size(), 1);
    int total = candies.size();
    for (int i = 0; i < ratings.size(); ++i)
      makeCandyAdjustments(ratings, candies, total, i);
    for (int i = ratings.size() - 1; i >= 0; --i)
      makeCandyAdjustments(ratings, candies, total, i);
    return total;
  }

  void makeCandyAdjustments(vector<int> &ratings, vector<int> &candies,
                            int &total, int i) {
    if (i != 0 && ratings[i] > ratings[i - 1] &&
        !(candies[i] > candies[i - 1])) {
      total += (candies[i - 1] + 1 - candies[i]);
      candies[i] = candies[i - 1] + 1;
    }
    if (i != ratings.size() - 1 && ratings[i] > ratings[i + 1] &&
        !(candies[i] > candies[i + 1])) {
      total += (candies[i + 1] + 1 - candies[i]);
      candies[i] = candies[i + 1] + 1;
    }
  }
};
