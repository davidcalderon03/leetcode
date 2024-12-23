class Solution {
public:
  bool canChange(string start, string target) {
    int index1 = 0, index2 = 0;
    while (index1 < start.length() || index2 < target.length()) {
      bool found1 = false, found2 = false;
      while (index1 < start.length()) {
        if (start[index1] != '_') {
          found1 = true;
          break;
        }
        index1++;
      }
      while (index2 < target.length()) {
        if (target[index2] != '_') {
          found2 = true;
          break;
        }
        index2++;
      }

      if (found1 != found2) {
        return false;
      } else if (found1 == false) {
        return true;
      } else if (start[index1] != target[index2]) {
        return false;
      }

      if (start[index1] == 'L' && index1 < index2) {
        return false;
      }
      if (start[index1] == 'R' && index1 > index2) {
        return false;
      }
      index1++;
      index2++;
    }
    return true;
  }
};
