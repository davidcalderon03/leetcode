class Solution {
public:
  bool isNumber(string s) {
    bool seenE = false, seenDecimal = false, seenNumSign = false,
         seenESign = false, seenNumbers = false, seenENumbers = false;
    for (int i = 0; i < s.length(); ++i) {
      if ((s[i] == '-' || s[i] == '+') &&
          ((!seenNumSign && i == 0) ||
           (!seenESign && i > 0 && (s[i - 1] == 'e' || s[i - 1] == 'E')))) {
        if (seenE) {
          seenESign = true;
        } else {
          seenNumSign = true;
        }
        continue;
      } else if ((s[i] == 'e' || s[i] == 'E') && i > 0 && i < s.length() - 1 &&
                 !seenE && seenNumbers) {
        seenE = true;
        continue;
      } else if (s[i] >= '0' && s[i] <= '9') {
        if (seenE) {
          seenENumbers = true;
        } else {
          seenNumbers = true;
        }
        continue;
      } else if (s[i] == '.' && (i > 0 || i < s.length() - 1) && !seenDecimal &&
                 !seenE) {
        seenDecimal = true;
        continue;
      } else {
        return false;
      }
    }
    return seenNumbers && (seenE == seenENumbers);
  }
};
