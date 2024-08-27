class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int operations = 0;
        while (left < right) {
            int current = nums[left] + nums[right];
            if (current < k) left++;
            else if (current > k) right--;
            else {
                operations++;
                left++;
                right--;
            }
        }
        return operations;
    }
};
