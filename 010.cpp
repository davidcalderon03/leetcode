class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<int, bool> cache;
        return helper(s, p, 0, 0, cache);
    }

    bool helper(string s, string p, int i, int j, unordered_map<int, bool>& cache) {
        if (cache.find(i * 1000000 + j) != cache.end()) return cache[i * 1000000 + j];

        if (i >= s.size() && j >= p.size()) return true;
        else if (j >= p.size()) return false;

        bool match = (i < s.size() && (p.at(j) == s.at(i) || p.at(j) == '.'));

        if (j + 1 < p.size() && p.at(j + 1) == '*') {
            cache[i * 1000000 + j] = (match && helper(s, p, i + 1, j, cache)) || // Continue
            helper(s, p, i, j + 2, cache); // Move to next
            return cache[i * 1000000 + j];
        }

        if (match) {
            cache[i * 1000000 + j] =  helper(s, p, i + 1, j + 1, cache);
            return cache[i * 1000000 + j];
        }
        else return false;
    }
};
