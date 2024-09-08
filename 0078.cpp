class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        set<int> remaining;
        for (int x : nums) remaining.insert(x);
        helper(remaining, {}, result);
        return result;
    }
    void helper(set<int> remaining, set<int> current_set, vector<vector<int>>& result) {
        vector<int> conversion;
        for (int x : current_set) conversion.push_back(x);
        result.push_back(conversion);
        for (int x : remaining) {
            set<int> new_set(current_set);
            new_set.insert(x);
            set<int> new_remaining(remaining);
            remaining.erase(x);
            helper(remaining, new_set, result);
        }
    }
};
