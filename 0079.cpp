class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    set<int> visited;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (helper(board, word, i, j, 0, visited)) {
          return true;
        }
      }
    }
    return false;
  }

  bool helper(vector<vector<char>> &board, string &word, int i, int j, int k,
              set<int> &visited) {
    if (board[i][j] != word[k] || visited.contains(i * 10 + j)) {
      return false;
    } else if (board[i][j] == word[k] && k == word.size() - 1) {
      return true;
    }
    visited.insert(i * 10 + j);
    bool result = (i > 0 && helper(board, word, i - 1, j, k + 1, visited)) ||
                  (j > 0 && helper(board, word, i, j - 1, k + 1, visited)) ||
                  (i < board.size() - 1 &&
                   helper(board, word, i + 1, j, k + 1, visited)) ||
                  (j < board[0].size() - 1 &&
                   helper(board, word, i, j + 1, k + 1, visited));
    visited.erase(i * 10 + j);
    return result;
  }
};
