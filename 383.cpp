class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> remaining_letters;
        for (int i = 0; i < magazine.length(); ++i) {
            remaining_letters[magazine.at(i)]++;
        }
        for (int i = 0; i < ransomNote.length(); ++i) {
            int available = remaining_letters[ransomNote.at(i)];
            if (available <= 0) return false;
            remaining_letters[ransomNote.at(i)]--;
        }
        return true;
    }
};
