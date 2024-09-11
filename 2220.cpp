class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flipped = 0;
        for (int i = 0; pow(2, i) <= max(start, goal); ++i) {
            int bit1 = (start >> i) & 1;
            int bit2 = (goal >> i) & 1;
            if (bit1 != bit2) flipped++;
        }
        return flipped;
    }
};
