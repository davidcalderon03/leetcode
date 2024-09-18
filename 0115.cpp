class Solution {
public:
    int numDistinct(string s, string t) {
        map<int, map<int, int>> cache;
        return helper(s, t, 0, 0, cache);
    }
    int helper(string s, string t, int i, int j, map<int, map<int, int>>& cache) {
        if (s.length() - i < t.length() - j) return 0;
        if (j >= t.length()) return 1;
        if (i >= s.length()) return 0;
        if (cache.contains(i) && cache[i].contains(j)) return cache[i][j];
        if (s[i] == t[j]) {
            cache[i][j] = helper(s, t, i + 1, j + 1, cache) + helper(s, t, i + 1, j, cache);
        } else {
            cache[i][j] = helper(s, t, i + 1, j, cache);
        }
        return cache[i][j];
    }
};
