class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                result.push_back(result[i >> 1] + 1);
            } else {
                result.push_back(result[i >> 1]);
            }
        }
        return result;
    }
};
