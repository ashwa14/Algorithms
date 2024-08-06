//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int row, col;

    void dfs(int i, int j, int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &path)
    {
        if (i < 0 or j < 0 or i >= row or j >= col or vis[i][j] or grid[i][j] == 0)
            return;

        vis[i][j] = 1;
        int ni = i - x, nj = j - y;

        path.push_back({ni, nj});

        dfs(i + 1, j, x, y, grid, vis, path);
        dfs(i - 1, j, x, y, grid, vis, path);
        dfs(i, j + 1, x, y, grid, vis, path);
        dfs(i, j - 1, x, y, grid, vis, path);
    }

    void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &path)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (q.size())
        {
            auto top = q.front();
            q.pop();
            int r = top.first, c = top.second;
            path.push_back({r - i, c - j});
            for (auto &cord : dir)
            {
                int x = r + cord.first, y = c + cord.second;
                if (x >= 0 and y >= 0 and x < row and y < col and vis[x][y] == 0 and grid[x][y] == 1)
                {
                    q.push({x, y});
                    vis[x][y] = 1;
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        row = grid.size(), col = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> vis(row, vector<int>(col));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (vis[i][j] == 0 and grid[i][j] == 1)
                {
                    vector<pair<int, int>> path;
                    // dfs(i, j, i, j, grid, vis, path);
                    bfs(i, j, grid, vis, path);
                    st.insert(path);
                }
            }
        }

        return st.size();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends