class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, int> mapping;
        set<vector<int>> result_as_set;
        for (int x : nums) mapping[x]++;
        helper(mapping, {}, result, result_as_set);
        return result;
    }   
    void helper(unordered_map<int, int> mapping, vector<int> current, vector<vector<int>>& result, set<vector<int>>& result_as_set) {
        result.push_back(current);
        for (const auto& [k, v] : mapping) {
            std::cout << k << " " << v << std::endl;
            if (v > 0) {
                current.push_back(k);
                sort(current.begin(), current.end());
                if (result_as_set.find(current) == result_as_set.end()) {
                    result_as_set.insert(current);
                    unordered_map<int, int> map_copy = mapping;
                    map_copy[k]--;
                    helper(map_copy, current, result, result_as_set);
                }
                current.erase(find(current.begin(), current.end(), k));
            }
        }
    }
};
