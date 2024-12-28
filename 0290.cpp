class Solution {
public:
  bool wordPattern(string pattern, string s) {
    vector<string> words;
    int position;
    while ((position = s.find(' ')) != string::npos) {
      words.push_back(s.substr(0, position));
      std::cout << words.back() << " ";
      s.erase(0, position + 1);
    }
    words.push_back(s);
    if (pattern.length() != words.size()) {
      return false;
    }
    unordered_map<char, string> mapping;
    set<string> unique_words;
    for (int i = 0; i < pattern.size(); ++i) {
      if (!mapping.contains(pattern[i])) {
        if (unique_words.contains(words[i])) {
          return false;
        }
        unique_words.insert(words[i]);
        mapping[pattern[i]] = words[i];
      } else if (mapping[pattern[i]] != words[i]) {
        return false;
      }
    }
    return true;
  }
};
