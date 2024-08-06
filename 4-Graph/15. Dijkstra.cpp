//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //? Function to find the  shortest distance of all the vertices
    //* from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        // ! Nothing new here, just using priority queue instead of queue in standard BFS

        //! even with normal queue it will give correct answer but it will be slower in that case.

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, S});

        vector<int> dist(V, INT_MAX);
        dist[S] = 0;

        while (q.size())
        {
            auto top = q.top();
            int d = top.first, node = top.second;
            q.pop();

            for (auto &child : adj[node])
            {
                int childNode = child[0], weight = child[1];

                if (dist[childNode] > d + weight)
                {
                    dist[childNode] = d + weight;
                    q.push({d + weight, childNode});
                }
            }
        }

        return dist;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends