class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mapping;
        for (int i = 0; i < nums.size(); ++i) {
            mapping[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); ++i) {
            vector<int> indices = mapping[nums[i]];
            for (int j = 0; j < indices.size(); ++j) {
                if (i != indices[j] && abs(i - indices[j]) <= k) return true;
            }
        }
        return false;
    }
};
