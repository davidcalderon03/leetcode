class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> master_map;
    int min_length = INT_MAX, index = -1;
    int count = 0;
    for (int i = 0; i < t.length(); ++i) {
      master_map[t[i]]++;
    }
    int i = 0;
    for (int j = 0; j < s.length(); ++j) {
      if (master_map.contains(s[j])) {
        master_map[s[j]]--;
        if (master_map[s[j]] >= 0) {
          count++;
        }
      }
      while (count == t.length()) {
        if ((j - i + 1) < min_length) {
          min_length = j - i + 1;
          index = i;
        }
        if (master_map.contains(s[i])) {
          if (master_map[s[i]] >= 0) {
            count--;
          }
          master_map[s[i]]++;
        }
        ++i;
      }
    }
    return index == -1 ? "" : s.substr(index, min_length);
  }
};
