#include <bits/stdc++.h>

using namespace std;

int count(const vector<string> &board, int col, int row)
{
    int c1 = 0, c2 = 0;
    for (int i = col; i < col + 8; ++i)
    {
        for (int j = row; j < row + 8; ++j)
        {
            if ((i + j) % 2 == 0)
            {
                if (board[i][j] != 'W')
                    ++c1;
                else
                    ++c2;
            }
            else
            {
                if (board[i][j] != 'B')
                    ++c1;
                else
                    ++c2;
            }
        }
    }
    return min(c1, c2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    
    vector<string> board(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    
    int res = 64;
    for (int i = 0; i <= n - 8; ++i)
    {
        for (int j = 0; j <= m - 8; ++j)
        {
            res = min(res, count(board, i, j));
        }
    }
    cout << res << "\n";
}