class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        map<int, map<int, map<int, int>>> cache;
        return helper(0, 0, 0, s1, s2, s3, cache);
    }

    bool helper(int i, int j, int k, string s1, string s2, string s, map<int, map<int, map<int, int>>>& cache) {
        if (cache.contains(k) && cache[k].contains(i) && cache[k][i].contains(j) && cache[k][i][j] == 1) return false;
        cache[k][i][j] = 1;
        if (k >= s.length() && i >= s1.length() && j >= s2.length()) return true;
        if (s1[i] != s[k] && s2[j] != s[k]) return false;
        bool result = false;
        if (i < s1.size() && s1[i] == s[k]) {
            result = result || helper(i + 1, j, k + 1, s1, s2, s, cache);
        }
        if (j < s2.size() && s2[j] == s[k]) {
            result = result || helper(i, j + 1, k + 1, s1, s2, s, cache);
        }
        return result;
    }
};
