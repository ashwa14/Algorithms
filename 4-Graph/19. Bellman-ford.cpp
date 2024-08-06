// Dijsktra's Algorithm fails for negative weight cycles. Bellman-Ford Algorithm can detect negative weight cycles.
// Bellman Ford Algorithm  is also for finding shortest path of each node from source just like as Dijkstra's Algorithm (but this will not work for negative weight).

// Key Points of Bellman Ford Algorithm :-

// * It will work for Negative weights
// Helps to detect negative cycle
// * will not work for negative cycle (if negative cycle is present then it will detect it)
// * will only work for directed graph
// In case of undirected graph ,convert it into directed graph

// *! Time complexity is O(N-1)*E which is more than Dijkstra's algorithm ( E*log(V) ) but this algo helps to detect negative cycle in graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        /*
        Since in a graph of V nodes, in worst case, you will
        take V—1 edges to reach from the first to the last,
        thereby we iterate for V—1 iterations.
        */
        for (int i = 0; i < V - 1; i++)
        {
            for (auto &child : edges)
            {
                int u = child[0], v = child[1], w = child[2];
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // negative cycle detection
        for (auto &child : edges)
        {
            int u = child[0], v = child[1], w = child[2];
            if (dist[u] + w < dist[v])
                return {-1};
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
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends