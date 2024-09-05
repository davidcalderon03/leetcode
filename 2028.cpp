class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total_present = 0;
        for (int x : rolls) total_present += x;
        int remaining = mean * (n + rolls.size()) - total_present;
        vector<int> result;

        if ((float)remaining / (float)n > 6.0 ||
        (float)remaining / (float)n < 1.0) return {};
        while (remaining > 0) {
            if (n == 1) {
                result.push_back(remaining);
                break;
            }
            result.push_back(round((float)remaining / (float)n));
            remaining -= round((float)remaining / (float)n);
            n--;
        }
        return result;
    }
};
