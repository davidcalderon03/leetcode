class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        for (int i = 0; i < s.size(); ++i) {
            int current_longest = 0;
            int stack = 0;
            for (int j = i; j < s.size(); ++j) {
                if (s.at(j) == '(') {
                    stack++;
                } else {
                    if (stack <= 0) {
                        break;
                    } else {
                        if (stack == 1) {
                            current_longest = j - i + 1;
                        }
                        stack--;
                    }
                }
            }
            longest = std::max(longest, current_longest);
        }
        return longest;
    }
};
