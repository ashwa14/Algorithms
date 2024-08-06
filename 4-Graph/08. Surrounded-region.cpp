#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}
class Solution
{
    int m, n;

    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &vis)
    {
        if (i < 0 or j < 0 or i >= m or j >= n or vis[i][j] or board[i][j] == 'X')
            return;

        vis[i][j] = 1;

        dfs(i + 1, j, board, vis);
        dfs(i - 1, j, board, vis);
        dfs(i, j + 1, board, vis);
        dfs(i, j - 1, board, vis);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' and (i == 0 or i == m - 1 or j == 0 or j == n - 1))
                {
                    dfs(i, j, board, vis);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vis[i][j] == 0 and board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};