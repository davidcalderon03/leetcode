class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long total = 0;
        long k2 = k;
        for (int x : chalk) total += x;
        k2 = k2 % total;
        std::cout << k << std::endl;
        for (int i = 0; i < chalk.size(); ++i) {
            k2 -= chalk[i];
            if (k2 < 0) return i;
        }
        return 0;
    }
};
