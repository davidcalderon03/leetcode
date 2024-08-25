class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = -1;
        bool placed = false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int left_ptr = i + 1;
            int right_ptr = nums.size() - 1;
            while (left_ptr < right_ptr) {
                int current = nums[i] + nums[left_ptr] + nums[right_ptr];
                if (!placed || abs(current - target) < abs(result - target)) {
                        result = current;
                        placed = true;
                }
                if (current < target) left_ptr++;
                else right_ptr--;
            }
        }
        return result;
    }
};
