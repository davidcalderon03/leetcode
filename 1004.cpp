class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int num_flipped = 0;
        int current_size = 0;
        int maximum_size = 0;
        while (right < nums.size() && left < nums.size()) {
            while (right < nums.size() &&
            (nums[right] == 1 || num_flipped < k)) {
                current_size++;
                if (nums[right] == 0) num_flipped++;
                right++;
            }
            maximum_size = max(maximum_size, current_size);
            
            if (nums[left] == 0) num_flipped--;
            current_size--;
            left++;
        }
        return maximum_size;
    }
};
