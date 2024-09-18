class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        bool inBlockComment = false;
        bool inLineComment = false;
        string current_line = "";
        for (string s : source) {
            for (int i = 0; i < s.size(); ++i) {
                if (inBlockComment == false && inLineComment == false && i < s.size() - 1 && s[i] == '/' && s[i + 1] == '*') {
                    inBlockComment = true;
                    ++i;
                } else if (inBlockComment == false && inLineComment == false && i < s.size() - 1 && s[i] == '/' && s[i + 1] == '/') {
                    inLineComment = true;
                    ++i;
                } else if (inBlockComment == true && inLineComment == false && i < s.size() - 1 && s[i] == '*' && s[i + 1] == '/') {
                    inBlockComment = false;
                    ++i;
                } else if (inBlockComment == false && inLineComment == false) {
                    current_line += s[i];
                }
            }
            inLineComment = false;
            if (inBlockComment == false && current_line.size() > 0) {
                result.push_back(current_line);
                current_line = "";
            }
        }
        return result;
    }
};
