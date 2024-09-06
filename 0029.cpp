class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (divisor == 1) return dividend;
        int sign = (dividend > 0 == divisor > 0) ? 1 : -1;
        long result = 0;
        long a = abs((long)dividend), b = abs((long)divisor);
        while (a > 0) {
            int shift = 0;
            while (a >= (b << (shift + 1))) shift++;
            long sub = b << shift;
            if (sub > a) break;
            result += (long)1 << shift;
            a -= b << shift;
        }
        if (result > INT_MAX) result = INT_MAX;
        return result * sign;
    }
};
