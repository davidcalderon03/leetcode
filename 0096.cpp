class Solution {
public:
  int numTrees(int n) {
    vector<int> catalanNums(n + 1, 0);
    catalanNums[0] = 1;
    catalanNums[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        catalanNums[i] += catalanNums[j] * catalanNums[i - j - 1];
      }
    }
    return catalanNums[n];
  }
};
