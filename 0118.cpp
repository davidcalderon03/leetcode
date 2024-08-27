class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}};
        for (int i = 1; i < numRows; ++i) {
            vector<int> next;
            for (int j = 0; j < result[i - 1].size() + 1; ++j) {
                int currentNum = 0;
                if (j != 0) currentNum += result[i - 1][j - 1];
                if (j != result[i - 1].size()) currentNum += result[i - 1][j];
                next.push_back(currentNum);
            }
            result.push_back(next);
        }
        return result;
    }
};
