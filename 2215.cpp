class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1_set(nums1.begin(), nums1.end());
        set<int> nums2_set(nums2.begin(), nums2.end());
        vector<int> ans0;
        vector<int> ans1;
        for (int x : nums2_set) {
            if (nums1_set.find(x) == nums1_set.end()) {
                ans1.push_back(x);
            }
        }
        for (int x : nums1_set) {
            if (nums2_set.find(x) == nums2_set.end()) {
                ans0.push_back(x);
            }
        }
        return {ans0, ans1};
    }
};
