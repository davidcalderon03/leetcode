class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> previous = {1};
        vector<int> next = previous;
        for (int i = 0; i < rowIndex; ++i) {
            next.clear();
            for (int j = 0; j < previous.size() + 1; ++j) {
                int currentNum = 0;
                if (j != 0) currentNum += previous[j - 1];
                if (j != previous.size()) currentNum += previous[j];
                next.push_back(currentNum);
            }
            previous = next;
        }
        return previous;
    }
};
