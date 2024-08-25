class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            seen[nums[i]]++;
        }
        for (const auto& [k, v] : seen) {
            if (v == 1) return k;
        }
        return 0;
    }
};
