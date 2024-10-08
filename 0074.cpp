class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() * matrix[0].size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int val = matrix[mid / matrix[0].size()][mid % matrix[0].size()];
            if (val < target) {
                low = mid + 1;
            } else if (val > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
