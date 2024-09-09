class Solution {
public:
    int rob(vector<int>& nums) {
        map<int, int> visited;
        int maximum = 0;
        for (int i = 0; i < nums.size(); ++i)
            helper(nums, i, 0, maximum, visited);  
        return maximum;
    }
    void helper(vector<int>& nums, int index, int total, int& maximum, map<int, int>& visited) {
        if (index >= nums.size()) {
            maximum = max(maximum, total);
            return;
        } else if (visited.find(index) != visited.end() && visited[index] >= total) {
            return;
        }
        visited[index] = total;
        total += nums[index];
        for (int i = index + 2; i < nums.size() + 2; ++i) {
            helper(nums, i, total, maximum, visited);
        }
    }
};
