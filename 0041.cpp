class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // Remove all negatives
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) nums[i] = 0;
        }


        // Create mapping
        for (int i = 0; i < nums.size(); ++i) {
            int val = abs(nums[i]);
            if (1 <= val && val <= nums.size()) {
                if (nums[val - 1] > 0) { // In case it was already negative
                    nums[val - 1] *= -1;
                } else if (nums[val - 1] == 0) {
                    nums[val - 1] = -(nums.size() + 1);
                }
            }
        }

        for (int n = 1; n <= nums.size(); ++n) {
            if (nums[n - 1] >= 0) return n;
        }
        return nums.size() + 1;
        
        
        // [1, -1, 2, 0]
        // [1, 0, 2, 0]
    }
};
