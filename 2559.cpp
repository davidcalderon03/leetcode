class Solution {
public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    set<int> vowels = {'a', 'e', 'i', 'o', 'u'};
    vector<int> prefixSums(words.size() + 1, 0);
    int total = 0;
    for (int i = 0; i < words.size(); ++i) {
      if (vowels.contains(words[i][0]) &&
          vowels.contains(words[i][words[i].length() - 1])) {
        total++;
      }
      prefixSums[i + 1] = total;
    }
    vector<int> result(queries.size(), 0);
    for (int i = 0; i < queries.size(); ++i) {
      result[i] = prefixSums[queries[i][1] + 1] - prefixSums[queries[i][0]];
    }
    return result;
  }
};
