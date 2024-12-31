class Solution {
public:
  bool isMatch(string s, string p) {
    unordered_map<int, bool> cache;
    return helper(s, p, 0, 0, cache);
  }

  bool helper(string &s, string &p, int i, int k,
              unordered_map<int, bool> &cache) {
    int index = i * 5000 + k;
    if (cache.contains(index)) {
      return cache[index];
    }
    if (i >= s.length() && k >= p.length()) {
      cache[index] = true;
    } else if (i >= s.length() && p[k] == '*') {
      cache[index] = helper(s, p, i, k + 1, cache);
    } else if (i < s.length() && k < p.length()) {
      if (s[i] == p[k] || p[k] == '?') {
        cache[index] = helper(s, p, i + 1, k + 1, cache);
      } else if (p[k] == '*') {
        cache[index] = helper(s, p, i + 1, k + 1, cache) ||
                       helper(s, p, i, k + 1, cache) ||
                       helper(s, p, i + 1, k, cache);
      }
    } else {
      cache[index] = false;
    }
    return cache[index];
  }
};
