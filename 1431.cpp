class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = INT_MIN;
        for (int x : candies) {
            maximum = max(maximum, x);
        }
        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= maximum) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        return result;

    }
};
