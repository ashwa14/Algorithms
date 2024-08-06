#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

// BFS Solution

class Solution
{
    int m, n;

    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    /*
     Following problem is an example of Multi Source BFS. In such case first push all the sources in the queue and then start the BFS.
    */

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        m = mat.size(), n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n)), vis(m, vector<int>(n));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                }
            }
        }

        while (q.size())
        {
            auto top = q.front();
            int x = top.first.first, y = top.first.second, dist = top.second;
            q.pop();

            if (mat[x][y] == 1)
            {
                ans[x][y] = dist;
            }

            for (auto &d : dir)
            {
                int x1 = x + d.first, y1 = y + d.second;

                if (x1 >= 0 and y1 >= 0 and x1 < m and y1 < n and vis[x1][y1] == 0)
                {
                    q.push({{x1, y1}, dist + 1});
                    vis[x1][y1] = 1;
                }
            }
        }

        return ans;
    }
};

// DP Solution

class Solution
{ // 48 ms, faster than 99.64%
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), INF = m + n; // The distance of cells is up to (M+N)
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (mat[r][c] == 0)
                    continue;
                int top = INF, left = INF;
                if (r - 1 >= 0)
                    top = mat[r - 1][c];
                if (c - 1 >= 0)
                    left = mat[r][c - 1];
                mat[r][c] = min(top, left) + 1;
            }
        }
        for (int r = m - 1; r >= 0; r--)
        {
            for (int c = n - 1; c >= 0; c--)
            {
                if (mat[r][c] == 0)
                    continue;
                int bottom = INF, right = INF;
                if (r + 1 < m)
                    bottom = mat[r + 1][c];
                if (c + 1 < n)
                    right = mat[r][c + 1];
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};