#include <string>
#include <vector>

using namespace std;

void set(vector<vector<int>>& board, int col, int row, int y, int x) {
    for (int i = y - 1; i <= y + 1; ++i) {
        for (int j = x - 1; j<= x+1; ++j) {
            if (i >= 0 && i < col && j >= 0 && j < row && board[i][j] == 0) {
                board[i][j] = 2;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int col = board.size();
    int row = board[0].size();
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            if (board[i][j] == 1) {
                set(board, col, row, i, j);
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            if (board[i][j] == 1 || board[i][j] == 2) {
                ++sum;
            }
        }
    }
    return row * col - sum;
}