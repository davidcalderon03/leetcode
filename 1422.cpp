class Solution {
public:
  int maxScore(string s) {
    int scoreLeft = (s[0] == '0'), scoreRight = 0;
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] == '1') {
        scoreRight++;
      }
    }
    int maxScore = scoreLeft + scoreRight;
    for (int i = 1; i < s.length() - 1; ++i) {
      if (s[i] == '0') {
        scoreLeft++;
      } else {
        scoreRight--;
      }
      maxScore = max(maxScore, scoreLeft + scoreRight);
    }
    return maxScore;
  }
};
