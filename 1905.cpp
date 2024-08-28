class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> visited(grid1.size(), vector<int>(grid1[0].size()));
        int result = 0;
        for (int i = 0; i < grid1.size(); ++i) {
            for (int j = 0; j < grid1[0].size(); ++j) {
                if (grid2[i][j] && !visited[i][j]) {
                    bool valid = true;
                    generateIsland(valid, i, j, grid1, grid2, visited);
                    if (valid) result++;
                }
            }
        }

        return result;
    }
    void generateIsland(bool& valid, int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& visited) {
        if (i >= grid1.size() || j >= grid1[0].size() || i < 0 || j < 0 || !grid2[i][j] || visited[i][j]) {
            return;
        }
        if (!grid1[i][j]) valid = false;
        visited[i][j] = 1;
        generateIsland(valid, i + 1, j, grid1, grid2, visited);
        generateIsland(valid, i - 1, j, grid1, grid2, visited);
        generateIsland(valid, i, j + 1, grid1, grid2, visited);
        generateIsland(valid, i, j - 1, grid1, grid2, visited);
    }
};
