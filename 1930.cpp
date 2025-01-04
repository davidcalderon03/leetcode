class Solution {
public:
  int countPalindromicSubsequence(string s) {
    int total = 0;
    unordered_map<char, int> firstLocations, lastLocations;
    for (int i = 0; i < s.length(); ++i) {
      if (!firstLocations.contains(s[i])) {
        firstLocations[s[i]] = i;
      }
      lastLocations[s[i]] = i;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
      if (!firstLocations.contains(c) ||
          firstLocations[c] == lastLocations[c]) {
        continue;
      }
      set<char> charsSeen;
      for (int i = firstLocations[c] + 1; i < lastLocations[c]; ++i) {
        charsSeen.insert(s[i]);
      }
      total += charsSeen.size();
    }
    return total;
  }
};
