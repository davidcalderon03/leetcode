class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> intermediate_set;
        vector<int> result;
        set<int> result_set;
        for (int i = 0; i < nums1.size(); ++i) {
            intermediate_set.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (intermediate_set.find(nums2[i]) != intermediate_set.end() &&
            result_set.find(nums2[i]) == result_set.end()) {
                result.push_back(nums2[i]);
                result_set.insert(nums2[i]);
            }
        }
        return result;
    }
};
