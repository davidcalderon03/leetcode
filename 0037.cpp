class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { solver(board, 0); }

  bool solver(vector<vector<char>> &board, int pos) {
    int i = pos / 9, j = pos % 9;
    if (pos >= 81) {
      return true;
    } else if (board[i][j] != '.') {
      return solver(board, pos + 1);
    }
    for (char c = '1'; c <= '9'; ++c) {
      if (validChoice(board, i, j, c)) {
        board[i][j] = c;
        if (solver(board, pos + 1)) {
          return true;
        } else {
          board[i][j] = '.';
        }
      }
    }
    return false;
  }

  bool validChoice(vector<vector<char>> &board, int x, int y, char c) {
    for (int i = 0; i < 9; ++i) {
      if (board[x][i] == c || board[i][y] == c ||
          board[(x / 3) * 3 + (i / 3)][(y / 3) * 3 + (i % 3)] == c) {
        return false;
      }
    }
    return true;
  }
};
