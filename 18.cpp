class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                int left_ptr = j + 1, right_ptr = nums.size() - 1;
                while (left_ptr < right_ptr) {
                    long current = (long)nums[i] + (long)nums[j] + (long)nums[left_ptr] + (long)nums[right_ptr];
                    if (current == (long)target) {
                        result.push_back({nums[i], nums[j], nums[left_ptr], nums[right_ptr]});
                        while (left_ptr < right_ptr && nums[left_ptr] == nums[left_ptr + 1]) left_ptr++;
                        while (left_ptr < right_ptr && nums[right_ptr] == nums[right_ptr - 1]) right_ptr--;
                    }
                    if (current < (long)target) left_ptr++;
                    else right_ptr--;
                }
                while (j < nums.size() - 1 && nums[j] == nums[j + 1]) ++j;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
        }
        return result;
    }
};
