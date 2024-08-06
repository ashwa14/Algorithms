//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    stack<int> st;

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto &child : adj[node])
        {
            if (vis[child] == 0)
                dfs(child, adj, vis);
        }
        st.push(node);
    }
    void dfs1(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto &child : adj[node])
        {
            if (vis[child] == 0)
                dfs1(child, adj, vis);
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {

        vector<int> vis(V);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
                dfs(i, adj, vis);
        }

        vector<vector<int>> g(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto &c : adj[i])
            {
                g[c].push_back(i);
            }
        }
        int ans = 0;
        while (st.size())
        {
            int node = st.top();
            st.pop();
            if (vis[node] == 0)
            {
                dfs1(node, g, vis);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends