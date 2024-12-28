class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    vector<vector<bool>> newBoard(board.size(),
                                  vector<bool>(board[0].size(), 0));
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        int total = 0;
        bool left = (j == 0), right = (j == board[0].size() - 1);
        bool up = (i == 0), down = (i == board.size() - 1);

        if (!left)
          total += board[i][j - 1];
        if (!right)
          total += board[i][j + 1];
        if (!up)
          total += board[i - 1][j];
        if (!down)
          total += board[i + 1][j];
        if (!left && !up)
          total += board[i - 1][j - 1];
        if (!left && !down)
          total += board[i + 1][j - 1];
        if (!down && !right)
          total += board[i + 1][j + 1];
        if (!right && !up)
          total += board[i - 1][j + 1];

        // Set up new board
        if (board[i][j] == 1) {
          if ((total < 2 || total > 3)) {
            newBoard[i][j] = 0;
          } else {
            newBoard[i][j] = 1;
          }
        } else {
          if (total == 3) {
            newBoard[i][j] = 1;
          } else {
            newBoard[i][j] = 0;
          }
        }
      }
    }
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        board[i][j] = newBoard[i][j];
      }
    }
  }
};
