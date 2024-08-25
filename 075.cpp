class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors = {0, 0, 0};
        for (int i = 0; i < nums.size(); ++i) {
            colors[nums[i]]++;
        }
        std::cout << colors[0] << " " << colors[1] << " " << colors[2] << std::endl;
        int color = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (colors[color] == 0) color++;
            nums[i] = color;
            colors[color]--;
        }
    }
};
