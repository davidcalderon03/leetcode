class Solution {
public:
    string removeStars(string s) {
        stack<char> characters;
        string result = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                characters.pop();
            } else {
                characters.push(s[i]);
            }
        }
        while (!characters.empty()) {
            result.push_back(characters.top());
            characters.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
