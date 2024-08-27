class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        map<vector<int>, int> cols;
        int result = 0;

        // Form rows
        for (vector<int> row : grid) {
            rows[row]++;
        }

        //Form cols
        for (int j = 0; j < grid[0].size(); ++j) { // Per col
            vector<int> current_col;
            for (int i = 0; i < grid.size(); ++i) { // All rows
                current_col.push_back(grid[i][j]);
            }
            cols[current_col]++;
        }
        for (const auto& [k, v] : rows) {
            if (cols.contains(k)) result+= v * cols[k];
        }
        return result;
    }
};
