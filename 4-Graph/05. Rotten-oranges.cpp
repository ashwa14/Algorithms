#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> vis(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int time = 0;
        while (q.size())
        {
            auto top = q.front();
            q.pop();
            int x = top.first.first, y = top.first.second, t = top.second;
            for (auto &d : dir)
            {
                int i = x + d.first, j = y + d.second;

                if (i >= 0 and j >= 0 and i < m and j < n and vis[i][j] == 0 and grid[i][j] == 1)
                {
                    q.push({{i, j}, t + 1});
                    vis[i][j] = 1;
                    grid[i][j] = 2;
                    time = max(time, t + 1);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return time;
    }
};

int main()
{

    return 0;
}