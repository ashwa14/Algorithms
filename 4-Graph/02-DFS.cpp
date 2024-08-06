#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }

    //! DFS code
    vector<int> vis(n);
    dfs(0, adj, vis); // 0 is the source node

    // time complexity :- O(N+E)  (N = no of nodes, E = no of edges
    // space complexity :- O(N+E) + O(N) = O(N+E)  (adj list + vis array)  (for dfs)
    // imp :- also in worst case the recursion stack can go upto O(N) depth so space complexity can be O(N) in worst case

    return 0;
}