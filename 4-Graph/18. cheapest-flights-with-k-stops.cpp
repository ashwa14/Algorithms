#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        //? review : No need to use priority queue since the stops will be in increasing order so queue will also store them in increasing order

        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        queue<pair<int, pair<int, int>>> q;

        vector<vector<pair<int, int>>> adj(n);

        for (auto &f : flights)
        {
            int u = f[0], v = f[1], price = f[2];
            adj[u].push_back({v, price});
        }

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        q.push({0, {0, src}});

        int level = 0;

        while (q.size())
        {

            auto top = q.front();
            q.pop();

            int node = top.second.second, cost = top.second.first, stops = top.first;

            if (stops > k)
                continue;

            // imp  cost and dist[node] are not same always
            // cout << dist[node] << "--" << cost << endl;
            
            for (auto &child : adj[node])
            {
                int childNode = child.first, price = child.second;

                if (dist[childNode] > cost + price and stops <= k)
                {
                    dist[childNode] = cost + price;

                    q.push({stops + 1, {dist[childNode], childNode}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};