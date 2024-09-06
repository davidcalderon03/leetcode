class Solution {
public:
    bool canJump(vector<int>& nums) {
        int remaining = nums[0];
        for (int i = 0; i < nums.size() - 1; ++i) {
            remaining = max(remaining, nums[i]);
            if (remaining <= 0) return false;
            remaining--;
        }
        return true;
        // set<int> visited;
        // return canJumpHelper(nums, 0, visited);
    }

    // More complex and less efficient recursive solution.
    bool canJumpHelper(vector<int>& nums, int current_index, set<int>& visited) {
        // std::cout << current_index << std::endl;
        if (current_index >= nums.size() - 1) return true;
        if (visited.contains(current_index)) return false;
        visited.insert(current_index);
        if (nums[current_index] == 0) return false;
        bool result = false;
        for (int jump_size = nums[current_index]; jump_size > 0; --jump_size) {
            result = result || canJumpHelper(nums, current_index + jump_size, visited);
            if (result == true) break;
        }
        return result;
    }
};
