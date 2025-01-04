class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    helper(s, "", 0, 0, result);
    return result;
  }

  void helper(string s, string current, int whichPart, int i,
              vector<string> &result) {
    if (whichPart == 4 && i == s.length()) {
      current = current.substr(0, current.length() - 1);
      result.push_back(current);
      return;
    } else if (whichPart >= 4 || i >= s.length()) {
      return;
    }
    if (i < s.length() - 1 && s[i] != '0') {
      helper(s, current + s[i] + s[i + 1] + '.', whichPart + 1, i + 2, result);
    }
    if (i < s.length() - 2 && stoi(s.substr(i, 3)) <= 255 && s[i] != '0') {
      helper(s, current + s[i] + s[i + 1] + s[i + 2] + '.', whichPart + 1,
             i + 3, result);
    }

    helper(s, current + s[i] + '.', whichPart + 1, i + 1, result);
  }
};
