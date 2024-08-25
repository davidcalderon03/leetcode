class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> mins(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            mins[i] = INT_MAX;
        }
        mins[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= i + nums[i] && j < nums.size(); ++j) {
                mins[j] = std::min(mins[j], mins[i] + 1);
            }
        }
        return mins[mins.size() - 1];
    }
};
