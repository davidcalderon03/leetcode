class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string result = "";
        while (i < word1.size() && j < word2.size()) {
            result += word1.at(i);
            result += word2.at(j);
            ++i;
            ++j;
        }
        while (i < word1.size()) {
            result += word1.at(i);
            ++i;
        }
        while (j < word2.size()) {
            result += word2.at(j);
            ++j;
        } 
        return result;
    }
};
