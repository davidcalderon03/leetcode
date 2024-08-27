class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maximum = -DBL_MAX;
        int total = 0;
        for (int i = 0; i < k; ++i) {
            total += nums[i];
        }
        maximum = max(maximum, (double)total / (double)k);
        for (int i = k; i < nums.size(); ++i) {
            maximum = max(maximum, (double)total / (double)k);
            total += nums[i];
            total -= nums[i - k];
        }
        maximum = max(maximum, (double)total / (double)k);
        return maximum;
    }
};
