class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (seen.find(nums[i]) == seen.end()) seen.insert(nums[i]);
            else seen.erase(nums[i]);
        }
        for (int x : seen) return x;
        return 0;
    }
};
