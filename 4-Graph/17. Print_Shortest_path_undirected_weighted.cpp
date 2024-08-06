//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {

        vector<int> ans;
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, 1});

        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;

        // if intialize with -1 then too many segments fault
        vector<int> par(n + 1);
        // intially each node will be parent of itself
        for (int i = 0; i <= n; i++)
            par[i] = i;

        while (q.size())
        {
            auto top = q.top();
            q.pop();

            int d = top.first, node = top.second;

            for (auto &child : adj[node])
            {
                int v = child.first, w = child.second;

                if (dist[v] > dist[node] + w)
                {
                    dist[v] = dist[node] + w;
                    par[v] = node;
                    q.push({dist[v], v});
                }
            }
        }

        if (dist[n] == INT_MAX)
            return {-1};

        int node = n;

        while (par[node] != node)
        {
            ans.push_back(node);
            node = par[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends