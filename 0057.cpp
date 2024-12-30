class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    if (intervals.size() == 0) {
      return {newInterval};
    }
    int low = 0, high = intervals.size() - 1, mid = 0;
    while (high >= low) {
      mid = low + ((high - low) / 2);
      if ((mid < intervals.size() - 1 && newInterval[0] >= intervals[mid][0] &&
           newInterval[0] < intervals[mid + 1][0])) {
        break;
      }
      if (intervals[mid][0] >= newInterval[0]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (mid < intervals.size() - 1 && newInterval[0] > intervals[mid][1] &&
        newInterval[1] < intervals[mid + 1][0]) {
      intervals.insert(intervals.begin() + mid + 1, newInterval);
      return intervals;
    } else if (intervals[0][0] > newInterval[1]) {
      intervals.insert(intervals.begin(), newInterval);
      return intervals;
    } else if (intervals[intervals.size() - 1][1] < newInterval[0]) {
      intervals.insert(intervals.begin() + intervals.size(), newInterval);
      return intervals;
    } else if (newInterval[0] >= intervals[mid][0] &&
               newInterval[1] <= intervals[mid][1]) {
      return intervals;
    }
    vector<vector<int>> newIntervals;
    bool started = false;
    for (vector<int> interval : intervals) {
      if (!started && newInterval[0] >= interval[0] &&
          interval[1] >= newInterval[0]) {
        newIntervals.push_back({interval[0], max(newInterval[1], interval[1])});
        started = true;
      } else if (!started && interval[0] >= newInterval[0] &&
                 newInterval[1] >= interval[0]) {
        newIntervals.push_back(
            {newInterval[0], max(interval[1], newInterval[1])});
        started = true;
      } else if (interval[0] >= newInterval[0] &&
                 interval[1] <= newInterval[1]) {
        // Do nothing
      } else if (started && interval[0] >= newInterval[0] &&
                 newInterval[1] >= interval[0] &&
                 interval[1] >= newInterval[1]) {
        newIntervals[newIntervals.size() - 1][1] = interval[1];
      } else {
        newIntervals.push_back(interval);
      }
    }
    return newIntervals;
  }
};
