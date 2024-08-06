#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{

    void dfs(int node, vector<int> &vis, vector<vector<int>> &g)
    {
        vis[node] = 1;
        for (auto &child : g[node])
        {
            if (vis[child] == 0)
            {
                dfs(child, vis, g);
            }
        }
    }

    void bfs(int node, vector<int> &vis, vector<vector<int>> &g)
    {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while (q.size())
        {
            int root = q.front();
            q.pop();
            for (auto &child : g[root])
            {
                if (vis[child] == 0)
                {
                    q.push(child);
                    vis[child] = 1;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        /**
         * You are given an n x n matrix isConnected where isConnected[i][j] = 1
         * if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
         */

        int n = isConnected.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        int cc = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bfs(i, vis, g);
                cc++;
            }
        }
        return cc;
    }
};

int main()
{
    return 0;
}
