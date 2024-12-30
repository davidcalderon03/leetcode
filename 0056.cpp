class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) {
           return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
         });

    vector<vector<int>> newIntervals = {intervals[0]};
    for (vector<int> interval : intervals) {
      if (interval[0] > newIntervals.back()[1]) {
        newIntervals.push_back(interval);
      } else if (interval[1] > newIntervals.back()[1]) {
        newIntervals[newIntervals.size() - 1][1] = interval[1];
      }
    }
    return newIntervals;
  }
};
