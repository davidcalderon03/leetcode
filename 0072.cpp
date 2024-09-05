class Solution {
public:
    int minDistance(string word1, string word2) {
        map<string, map<int, map<int, int>>> cache;
        int minimum = word1.length() + word2.length();
        helper(word1, word2, 0, 0, 0, minimum, cache);
        return minimum;
    }

    void helper(string word1, string word2, int i, int j, int dist, int& minimum, map<string, map<int, map<int, int>>>& cache) {
        if (dist > minimum) return;
        if (cache.contains(word1) && cache[word1].contains(i) && cache[word1][i].contains(j) &&
            cache[word1][i][j] <= dist) return;
        cache[word1][i][j] = dist;
        if (i >= word1.length() && j >= word2.length() && i == j) {
            minimum = std::min(minimum, dist);
            return;
        } else if (word1[i] == word2[j]) {
            helper(word1, word2, i + 1, j + 1, dist, minimum, cache);
        } else {
            if (i < word1.length()) { //Erase
                char temp = word1[i];
                word1.erase(i, 1);
                helper(word1, word2, i, j, dist + 1, minimum, cache);
                word1.insert(i, {temp});
            }
            if (j < word2.length()) { // Insert
                word1.insert(i, {word2[j]});
                helper(word1, word2, i + 1, j + 1, dist + 1, minimum, cache);
                word1.erase(i, 1);
            }
            if (i < word1.length() && j < word2.length()) { // Exchange
                char temp = word1[i];
                word1[i] = word2[j];
                helper(word1, word2, i + 1, j + 1, dist + 1, minimum, cache);
                word1[i] = temp;
            }
        }
    }
};
