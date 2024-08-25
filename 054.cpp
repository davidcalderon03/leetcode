class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> seen(matrix.size(), std::vector<bool>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                seen[i][j] = false;
            }
        }
        vector<int> solution;
        int direction = 0; //0 is right, 1 is down, 2 is left, 3 is up
        int row = 0, col = 0;
        for (int i = 0; i < matrix.size() * matrix[0].size(); ++i) {
            if (
                (direction == 0 && (col == matrix[0].size() - 1 || seen[row][col + 1])) ||
                (direction == 1 && (row == matrix.size() - 1 || seen[row + 1][col])) ||
                (direction == 2 && (col == 0 || seen[row][col - 1])) ||
                (direction == 3 && (row == 0 || seen[row - 1][col]))
                ) {
                    direction = (direction + 1) % 4;
            }
            solution.push_back(matrix[row][col]);
            std::cout << matrix[row][col] << std::endl;
            seen[row][col] = true;

            switch(direction) {
                case 0: col++; break;
                case 1: row++; break;
                case 2: col--; break;
                default: row--; break;
            }
            
        }
        return solution;
    }
};
