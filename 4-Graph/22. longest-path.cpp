
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //*   https://www.techiedelight.com/find-cost-longest-path-dag/
    //*   https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

    int longestPathGraph(int V, vector<vector<int>> &edges, int S)
    {
        vector<vector<pair<int, int>>> adj(V);

        for (auto &child : edges)
        {
            int u = child[0], v = child[1], w = child[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(V, -1e9);
        dist[S] = 0;

        priority_queue<pair<int, int>> q;

        q.push({0, S});

        while (q.size())
        {
            auto top = q.top();
            q.pop();

            int u = top.second, d = top.first;

            for (auto &child : adj[u])
            {
                int v = child.first, w = child.second;
                if (dist[v] < d + w)
                {
                    dist[v] = d + w;
                    q.push({dist[v], v});
                }
            }
        }
        int maxDist = -1e9;

        for (int i = 0; i < V; i++)
        {
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        int res = obj.longestPathGraph(N, edges, src);

        cout << res << "\n";
    }
    return 0;
}

// } Driver Code Ends