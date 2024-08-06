#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

class Solution
{

    bool dfs(int i, vector<vector<int>> &graph, vector<int> &vis, vector<int> &path, set<int> &cycle)
    {
        vis[i] = 1;
        path[i] = 1;

        bool is = false;

        for (auto &child : graph[i])
        {
            if (vis[child] == 0)
            {
                if (cycle.count(child))
                {
                    is = true;
                }
                if (!is)
                    is |= dfs(child, graph, vis, path, cycle);
            }
            else if (path[child])
            {
                is = true;
            }
            if (cycle.count(child))
                is = true;
        }
        if (is)
            cycle.insert(i);
        path[i] = 0;
        return is;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> ans;
        int n = graph.size();
        vector<int> vis(n), path(n);

        set<int> cycle;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, graph, vis, path, cycle);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (cycle.count(i) == 0)
                ans.push_back(i);
        }

        return ans;
    }
};