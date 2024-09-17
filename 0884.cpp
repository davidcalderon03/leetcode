class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> seen;
        std::stringstream ss1(s1);
        std::string word1;
        std::vector<std::string> words1;
        std::stringstream ss2(s2);
        std::string word2;
        std::vector<std::string> words2;
        while (std::getline(ss1, word1, ' ')) {
            words1.push_back(word1);
        }
        while (std::getline(ss2, word2, ' ')) {
            words2.push_back(word2);
        }
        for (string s : words1) {
            seen[s]++;
        }
        for (string s : words2) {
            seen[s]++;
        }
        vector<string> result;
        for (const auto& [k, v] : seen) {
            if (v == 1)
            result.push_back(k);
        }
        return result;
        
    }
};
