class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> word_map;
        int word_len = words[0].length();
        vector<int> result;
        for(string s : words) {
            word_map[s]++;
        }
        int max_index = s.length() - (words.size() * word_len);
        for (int offset = 0; offset < word_len; ++offset) {
            int start_index = offset;
            while (start_index <= max_index) {
                unordered_map<string, int> running_map;
                for (int i = start_index; i < s.length() && i - start_index < words.size() * word_len; i+= word_len) {
                    string substring = s.substr(i, word_len);
                    if (word_map.find(substring) == word_map.end()) {
                        break;
                    } else {
                        running_map[substring]++;
                    }
                    if (running_map == word_map) {
                        result.push_back(start_index);
                        break;
                    }
                }
                start_index += word_len;
            }
        }
        return result;
    }
};
