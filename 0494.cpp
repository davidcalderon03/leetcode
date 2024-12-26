class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int total = 0;
    differentWays(nums, 0, target, 0, total);
    return total;
  }

  void differentWays(vector<int> &nums, int runningSum, int target, int index,
                     int &total) {
    if (index >= nums.size()) {
      if (runningSum == target) {
        total++;
      }
      return;
    }
    differentWays(nums, runningSum + nums[index], target, index + 1, total);
    differentWays(nums, runningSum - nums[index], target, index + 1, total);
  }
};
