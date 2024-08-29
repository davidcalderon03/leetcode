class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int sets = 0;
        vector<bool> visited(stones.size());
        for (int i = 0; i < stones.size(); ++i) {
            if (!visited[i]) {
                sets++;
                search(stones, visited, i);
            }
        }
        return stones.size() - sets;
    }

    void search(vector<vector<int>>& stones, vector<bool>& visited, int index) {
        visited[index] = true;
        for (int i = 0; i < stones.size(); ++i) {
            if (!visited[i] && (stones[index][0] == stones[i][0]
                || stones[index][1] == stones[i][1])) {
                    search(stones, visited, i);
                }
        }
    }


};
