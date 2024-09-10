class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        long dp [m][n];
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (r == m - 1 && c == n - 1) {
                    dp[r][c] = 1;
                    continue;
                }

                if (obstacleGrid[r][c] == 1) continue;
                int total = 0;
                if (r + 1 < m && obstacleGrid[r + 1][c] != 1) {
                    total += dp[r + 1][c];
                }
                if (c + 1 < n && obstacleGrid[r][c + 1] != 1) {
                    total += dp[r][c + 1];
                }
                dp[r][c] = total;
            }
        }
        std::cout << dp[m - 1][n - 1];
        return dp[0][0];
        
    }

};
