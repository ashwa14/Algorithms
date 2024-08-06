#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
    int m, n, cc;

    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        if (i < 0 or j < 0 or i >= m or j >= n or vis[i][j] or grid[i][j] == '0')
            return;

        vis[i][j] = 1;

        // down
        dfs(i + 1, j, vis, grid);
        // up
        dfs(i - 1, j, vis, grid);
        // left
        dfs(i, j - 1, vis, grid);
        // right
        dfs(i, j + 1, vis, grid);
    }

    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        
        vis[i][j] = 1;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (q.size())
        {
            auto top = q.front();
            q.pop();
            int x = top.first, y = top.second;
            for (auto &d : dir)
            {
                int x1 = x + d.first, y1 = y + d.second;
                if (x1 >= 0 and y1 >= 0 and x1 < m and y1 < n and vis[x1][y1] == 0 and grid[x1][y1] == '1')
                {
                    q.push({x1,
                            y1});
                    vis[x1][y1] = 1;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size(), n = grid[0].size(), cc = 0;

        vector<vector<int>> vis(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' and vis[i][j] == 0)
                {
                    cc++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return cc;
    }
};
int main()
{

    return 0;
}
