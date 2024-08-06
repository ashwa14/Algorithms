#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

    //! BFS code
    // imp  TIME COMPLEXITY :- O(N+E)  (N = no of nodes, E = no of edges
    //! space complexity :- O(N+E) + O(N) = O(N+E)  (adj list + vis array)

    //? review  Version 1: Using dist vector

    /*
    This vector will be used to store the minimum distance of each node from
    the source node which is node = 0 in the BFS traversal.
     This is very useful when we want to find the shortest path between two nodes in an unweighted graph.
    */
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            //! means the current child node is not vischilded yet (dist[child] = INT_MAX)
            if (dist[node] + 1 < dist[child])
            {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }

    // Version 2: Using visited array
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
            }
        }
    }

    // version 3: Storing each level in a separate vector<vector<int>> level
    vector<vector<int>> level;
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> cur;
        while (size--)
        {
            int node = q.front();
            q.pop();
            cur.push_back(node);
            for (auto child : adj[node])
            {
                if (!vis[child])
                {
                    vis[child] = true;
                    q.push(child);
                }
            }
        }
        level.push_back(cur);
    }

    // version 4: shortest path from source to destination
    //*  very very important technique

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            if (dist[node] + 1 < dist[child])
            {
                dist[child] = dist[node] + 1;
                parent[child] = node;
                q.push(child);
            }
        }
    }
    if (dist[n - 1] == INT_MAX)
    {
        cout << "IMPOSSIBLE TO REACH n-1 node since no path available" << endl;
    }
    else
    {
        //! printing the shortest path from source (0) to destination (n-1)
        vector<int> path;
        for (int i = n - 1; i != -1; i = parent[i])
        {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        //! distance from source to destination
        cout << path.size() << endl;
        for (auto node : path)
        {
            cout << node + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}