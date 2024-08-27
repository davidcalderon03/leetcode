class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int x : nums) {
            if (x == 0) count++;
        }
        for (int i = 0; i < nums.size() - count; ++i) {
            if (nums[i] == 0) {
                for (int j = i; j < nums.size() - 1; ++j) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
                --i;
            }
        }
    }
};
