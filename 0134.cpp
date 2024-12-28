class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int fuel = 0, total_fuel = 0, start_index = 0;
    for (int i = 0; i < cost.size(); ++i) {
      total_fuel += (gas[i] - cost[i]);
      fuel += (gas[i] - cost[i]);
      if (fuel < 0) {
        fuel = 0;
        start_index = i + 1;
      }
    }
    if (total_fuel < 0) {
      return -1;
    }
    return start_index;
  }
};
