class Solution {
public:
    int mySqrt(int x) {
        int result = 0;
        for (long i = 0; i <= x; ++i) {
            if (i * i <= x) result = i;
            else break;
        }
        return result;
    }
};
