class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 0;
        bool zero_product = false;
        bool total_zero_product = false;
        std::vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (zero_product == true) {
                    total_zero_product = true;
                }
                zero_product = true;
            } else {
                if (product == 0) product = 1;
                product *= nums[i];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (total_zero_product) {
                result.push_back(0);
            }
            else if (nums[i] == 0) {
                result.push_back(product);
                continue;
            } else if (zero_product) {
                result.push_back(0);
            } else {
                result.push_back(product / nums[i]);
            }
        }
        return result;
    }
};
