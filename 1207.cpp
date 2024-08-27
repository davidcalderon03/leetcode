class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mapping;
        for (int x : arr) {
            mapping[x]++;
        }
        set<int> unique;
        for (const auto& [k, v] : mapping) {
            if (unique.find(v) == unique.end()) {
                unique.insert(v);
            } else {
                return false;
            }
        }
        return true;
    }
};
