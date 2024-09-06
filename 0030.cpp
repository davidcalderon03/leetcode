class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() * words[0].length() > s.length()) return {};
        map<string, int> mapping;
        int length = words[0].length();
        vector<int> result;
        for(string s : words) {
            mapping[s]++;
        }

        for (int offset = 0; offset < length; ++offset) {
            map<string, int> record;
            int index = offset;
            for (int i = 0; i < words.size(); ++i, index += length) {
                string current_word = s.substr(index, length);
                record[current_word]++;
            }
            while (index < s.length()) {
                if (mapping == record) {
                    result.push_back(index - words.size() * length);
                }
                string left = s.substr(index - words.size() * length, length);
                string right = s.substr(index, length);

                record[left]--;
                if (record[left] == 0) record.erase(left);
                record[right]++;
                index += length;
            }
            if (mapping == record) {
                result.push_back(index - words.size() * length);
            }
        }
        return result;
    }
};




// Sliding window approach:
// abcd efgh ijkl
//  bcde fghi jklm 
//   cdef ghij klmn
//    defg hijk lmno
