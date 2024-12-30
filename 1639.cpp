class Solution {
public:
  int numWays(vector<string> &words, string target) {
    vector<unordered_map<char, int>> frequencies(words[0].length());
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words[i].length(); ++j) {
        frequencies[j][words[i][j]]++;
      }
    }
    unordered_map<string, long> cache;
    return (int)(dfs(0, 0, frequencies, target, cache) % (1000000000 + 7));
  }

  long dfs(int i, int k, vector<unordered_map<char, int>> &frequencies,
           string &target, unordered_map<string, long> &cache) {
    string key = to_string(i) + " " + to_string(k);
    if (cache.contains(key)) {
      return cache[key];
    }
    if (i >= target.length() || k >= frequencies.size()) {
      return 0;
    } else if (i == target.length() - 1) {
      cache[key] = (frequencies[k][target[i]] +
                    dfs(i, k + 1, frequencies, target, cache)) %
                   (1000000000 + 7);
    } else if (frequencies[k].contains(target[i])) {
      cache[key] = (frequencies[k][target[i]] *
                        dfs(i + 1, k + 1, frequencies, target, cache) +
                    dfs(i, k + 1, frequencies, target, cache)) %
                   (1000000000 + 7);
    } else {
      cache[key] = dfs(i, k + 1, frequencies, target, cache) % (1000000000 + 7);
    }
    return cache[key];
  }
};
