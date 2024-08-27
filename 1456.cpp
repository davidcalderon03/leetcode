class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        int maximum = 0;
        int current = 0;
        for (int i = 0; i < k; ++i) {
            if (vowels.contains(s[i])) current++;
        }
        int left = 0;
        int right = k - 1;
        maximum = current;

        while (right < s.size()) {
            if (vowels.contains(s[left])) current--;
            left++;
            right++;
            if (vowels.contains(s[right])) current++;

            maximum = max(maximum, current);
        }
        return maximum;
    }
};
