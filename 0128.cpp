class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, int> lengths;
    int maxLength = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (lengths.contains(nums[i])) {
        continue;
      }
      int low = lengths.contains(nums[i] - 1) ? lengths[nums[i] - 1] : 0;
      int high = lengths.contains(nums[i] + 1) ? lengths[nums[i] + 1] : 0;
      int length = 1 + low + high;
      lengths[nums[i] - low] = lengths[nums[i] + high] = lengths[nums[i]] =
          length;
      maxLength = max(maxLength, lengths[nums[i]]);
    }
    return maxLength;
  }
};
