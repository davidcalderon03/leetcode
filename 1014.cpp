class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int i = 0;
    int maximum = INT_MIN;
    for (int j = 1; j < values.size(); ++j) {
      maximum = std::max(maximum, values[i] + values[j] + i - j);
      if (values[j] + j > values[i] + i) {
        i = j;
      }
    }
    return maximum;
  }
};
