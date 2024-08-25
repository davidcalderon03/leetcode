class Solution {
public:
    string reverseWords(string s) {
        string result;
        std::vector<string> words;
        string current_word = "";
        bool has_content = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s.at(i) == ' ') {
                if (has_content) {
                    words.push_back(current_word);
                    current_word = "";
                    has_content = false;
                }
            } else {
                current_word += s.at(i);
                has_content = true;
            }
        }
        if (has_content) words.push_back(current_word);

        for (int i = words.size() - 1; i >= 1; --i) {
            result += words[i];
            result += ' ';
        }
        if (words.size() > 0) result += words[0];
        return result;
    }
};
