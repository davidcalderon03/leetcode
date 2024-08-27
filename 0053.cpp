class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN, max_ending_here = 0;
        for (int i = 0; i < nums.size(); ++i) {
            max_ending_here += nums[i];
            maximum = max(maximum, max_ending_here);
            max_ending_here = max(0, max_ending_here);
        }
        return maximum;
    }
};
