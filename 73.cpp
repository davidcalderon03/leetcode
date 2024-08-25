class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> zero_rows;
        set<int> zero_cols;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zero_rows.insert(i);
                    zero_cols.insert(j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (zero_rows.find(i) != zero_rows.end() ||
                    zero_cols.find(j) != zero_cols.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
