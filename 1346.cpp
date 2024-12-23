class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    std::unordered_set<int> seen;
    for (int i = 0; i < arr.size(); ++i) {
      if (seen.contains(arr[i] * 2) ||
          (arr[i] % 2 == 0 && seen.contains(arr[i] / 2))) {
        return true;
      }
      seen.insert(arr[i]);
    }
    return false;
  }
};
