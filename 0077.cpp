class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    recurse({}, result, k, 1, n);
    return result;
  }

  void recurse(vector<int> current, vector<vector<int>> &result, int level,
               int a, int n) {
    if (level == 0) {
      result.push_back(current);
      return;
    }
    for (int i = a; i <= n - level + 1; ++i) {
      current.push_back(i);
      recurse(current, result, level - 1, i + 1, n);
      current.pop_back();
    }
  }
};
