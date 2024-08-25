class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int running_total = 0;
        int num_elements = 0;
        int result = INT_MAX;
        int left = 0;
        int right = 0;

        if (nums[0] >= target) result = 1;
        running_total = nums[0];
        num_elements++;

        while (right + 1 < nums.size()) {
            std::cout << "Left: " << left << " Right: " << right << std::endl;
            right++;
            num_elements++;
            running_total += nums[right];
            while (left <= right && running_total >= target) {
                result = std::min(result, num_elements);
                running_total -= nums[left++];
                num_elements--;
            }
        }
        if (result == INT_MAX) return 0;
        return result;
    }
};
