class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> right_maxes(height.size());
        int left_max = 0;
        int right_max = 0;
        int result = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            right_maxes[i] = right_max;
            right_max = std::max(right_max, height[i]);
        }

        // Optimize to calculate left max concurrently
        for (int i = 0; i < height.size(); ++i) {
            int min = std::min(left_max, right_maxes[i]);
            result += std::max(0, min - height[i]);
            left_max = max(left_max, height[i]);
        }
        return result;
    }
};
