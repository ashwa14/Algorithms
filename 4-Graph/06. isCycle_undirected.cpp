//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    bool bfs(int V, vector<int> adj[], int node)
    {

        vector<int> vis(V);
        queue<pair<int, int>> q;

        q.push({node, -1});
        vis[node] = 1;

        while (q.size())
        {
            auto front = q.front();
            q.pop();
            int node = front.first, parent = front.second;
            for (auto child : adj[node])
            {
                if (vis[child] == 0)
                {
                    q.push({child, node});
                    vis[child] = 1;
                }
                else
                {
                    if (child != parent)
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<int> adj[], int node, vector<int> &vis, int par)
    {
        vis[node] = 1;
        bool is = false;
        for (auto child : adj[node])
        {
            if (vis[child] == 0)
            {
                is |= dfs(adj, child, vis, node);
            }
            else
            {
                if (child != par)
                    return true;
            }
        }
        return is;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {

        vector<int> vis(V);
        for (int i = 0; i < V; i++)
        {
            // bfs
            if (bfs(V, adj, i))
                return true;
            // dfs
            if (vis[i] == 0 and dfs(adj, i, vis, -1))
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
