class Solution {
public:
  unordered_map<int, int> cache;
  int numDecodings(string s) {
    if (s[0] == '0') {
      return 0;
    }
    return numWays(s, 0);
  }

  int numWays(string s, int i) {
    if (cache.contains(i)) {
      return cache[i];
    } else if (i >= s.length()) {
      return 1;
    }
    bool onePossible = stoi(s.substr(i, 1)) <= 9 && stoi(s.substr(i, 1)) >= 1;
    bool twoPossible = i < s.length() - 1 && stoi(s.substr(i, 2)) <= 26 &&
                       stoi(s.substr(i, 2)) >= 10;
    if (i == s.length() - 1 && onePossible) {
      cache[i] = 1;
    } else if (twoPossible && onePossible) {
      cache[i] = numWays(s, i + 1) + numWays(s, i + 2);
    } else if (twoPossible) {
      cache[i] = numWays(s, i + 2);
    } else if (onePossible) {
      cache[i] = numWays(s, i + 1);
    } else {
      cache[i] = 0;
    }
    return cache[i];
  }
};
