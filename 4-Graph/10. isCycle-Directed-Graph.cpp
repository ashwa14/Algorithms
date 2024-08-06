/*
        0----> 1 ----> 2
         ⬇️  ⬇️      ⬇️
          \  |        |
           \ |        |
            3 ----> 4

    This is not a cycle because there is no back edge.
    Using only visited array will not work here. Beacause it's possible that we visit a node which is already visited but it's not a back edge.
    For example we start DFS form 0 --> 1--->2---> 4 so node 4  is marked as visited.
    Now we go to 3 from 0 then form 3 to 4 but we found that 4 is already visited, so there is a cycle but in reality there is no cycle since there is no backedge from 4---> 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &path)
    {
        vis[i] = 1;
        path[i] = 1;

        bool is = false;

        for (auto &child : adj[i])
        {
            if (vis[child] == 0)
            {
                is |= dfs(child, adj, vis, path);
                if (is)
                    return true;
            }
            else if (path[child] == 1)
                return true;
        }
        // backtracking
        path[i] = 0;
        return is;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V);

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                vector<int> path(V);
                bool is = dfs(i, adj, vis, path);
                if (is)
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
