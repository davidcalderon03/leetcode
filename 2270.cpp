class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    long leftSum = nums[0];
    long rightSum = 0;
    int numWays = 0;
    for (int i = 1; i < nums.size(); ++i) {
      rightSum += nums[i];
    }

    for (int i = 1; i < nums.size(); ++i) {
      if (leftSum >= rightSum) {
        numWays++;
      }
      leftSum += nums[i];
      rightSum -= nums[i];
    }
    return numWays;
  }
};
