#include <cmath>
class Solution {
public:
  string getPermutation(int n, int k) {
    string result = "";
    int shiftCount = 0;
    k--;
    vector<int> bank = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = n; i >= 1; --i) {
      int factorial = tgamma(i); // Factorial for i - 1
      int digit = (k / factorial);
      result += to_string(bank[digit]);
      bank.erase(bank.begin() + digit);
      k -= factorial * digit;
    }
    return result;
  }
};
