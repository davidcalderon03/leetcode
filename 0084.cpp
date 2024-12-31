class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    heights.push_back(0);
    stack<pair<int, int>> consideredHeights;
    int largestArea = heights[0];
    for (int i = 0; i < heights.size(); ++i) {
      int numPopped = 0;
      int startIndex = i;
      while (consideredHeights.size() > 0 &&
             consideredHeights.top().second > heights[i]) {
        pair<int, int> considered = consideredHeights.top();
        consideredHeights.pop();
        startIndex = considered.first;
        largestArea = max(largestArea, considered.second * (i - startIndex));
      }
      consideredHeights.push(make_pair(startIndex, heights[i]));
    }
    return largestArea;
  }
};
