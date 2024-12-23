class Solution {
public:
  string addSpaces(string s, vector<int> &spaces) {
    std::string result = "";
    int currentSpace = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (currentSpace < spaces.size() && spaces[currentSpace] == i) {
        result += ' ';
        currentSpace++;
      }
      result += s[i];
    }
    return result;
  }
};
