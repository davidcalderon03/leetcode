class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> vowel_order;
        for (int i = 0; i < s.size(); ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                vowel_order.push_back(s.at(i));
            }
        }
        int vowel_pointer = vowel_order.size() - 1;
        for (int i = 0; i < s.size(); ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                s[i] = vowel_order[vowel_pointer];
                vowel_pointer--;
            }
        }
        return s;
    }
};
