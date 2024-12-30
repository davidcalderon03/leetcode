class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    unordered_map<int, long> cache;
    return (int)(helper(low, high, zero, one, 0, cache) % (1000000000 + 7));
  }

  long helper(int low, int high, int zero, int one, int currentLength,
              unordered_map<int, long> &cache) {
    if (currentLength > high) {
      return 0;
    } else if (cache.contains(currentLength)) {
      return cache[currentLength];
    }
    int ways = currentLength >= low && currentLength <= high ? 1 : 0;
    cache[currentLength] =
        (ways + helper(low, high, zero, one, currentLength + zero, cache) +
         helper(low, high, zero, one, currentLength + one, cache)) %
        (1000000000 + 7);
    return cache[currentLength];
  }
};
