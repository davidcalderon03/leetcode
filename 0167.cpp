class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j && numbers[i] + numbers[j] != target) {
            int current_number = numbers[i] + numbers[j];
            if (current_number < target) {
                ++i;
            } else {
                --j;
            }
        }
        return {i + 1, j + 1};
    }
};
