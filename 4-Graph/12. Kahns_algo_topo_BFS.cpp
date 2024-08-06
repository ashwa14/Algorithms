/*
    This algo use the concept of indegree. When indegree of a node becomes equal to zero we insert it in the ans vector.

    - It’s a BFS algo, used for directed graphs.

    - First of all find indegree of all nodes and store in a indegree[ ] array.

    - Push all nodes with indegree==0 in a `queue<int> q`.

    - `While(q.size()!=0) keep iterating over the loop.`

    - `q.pop()`   and insert the front element into your `result`  array.

    - iterate over all the child of front node (same as we do in dfs).

    - `indegree[child]--`  and if `indegree[child]` become zero push `child` node in to the queue.

    - if after completing the loop indegree of any node is positive means cycle exist in the graph.

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<int> ind(V);
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            for (auto child : adj[i])
                ind[child]++;
        }

        for (int i = 0; i < V; i++)
            if (ind[i] == 0)
                q.push(i);

        while (q.size())
        {
            auto top = q.front();
            q.pop();
            ans.push_back(top);
            for (auto child : adj[top])
            {
                if (--ind[child] == 0)
                    q.push(child);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends