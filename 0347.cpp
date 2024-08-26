class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); ++i) {
            mapping[nums[i]]++;
        }

        vector<vector<int>> count_map(nums.size() + 1, vector<int>(0));
        std::cout << count_map.size() << std::endl;
        for (const auto& [k,v] : mapping) {
            count_map[v].push_back(k);
        }

        vector<int> result;
        for (int i = count_map.size() - 1; i >= 0; --i) {
            for (int j = 0; j < count_map[i].size(); ++j) {
                result.push_back(count_map[i][j]);
                if (result.size() >= k) return result;
            }
        }

        return result;
    }
};
