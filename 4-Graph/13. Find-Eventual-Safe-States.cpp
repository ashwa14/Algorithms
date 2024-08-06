#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}
/*
https://leetcode.com/problems/find-eventual-safe-states/
*/
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        // this is a reverse topological sort problem
        // we are using outdegree array to keep track of outdegree of each node and if it becomes 0 then we push it in the queue
        // and then we are using reverse graph to traverse the graph and reduce the outdegree of each node and if it becomes 0 then we push it in the queue
        
        int n = graph.size();
        vector<int> ans, out(n);
        queue<int> q;

        vector<vector<int>> outAdj(n);

        for (int i = 0; i < n; i++)
        {
            // creating reverse graph
            for (auto x : graph[i])
            {
                outAdj[x].push_back(i);
            }
            out[i] = graph[i].size();
            if (out[i] == 0)
                q.push(i);
        }

        while (q.size())
        {
            auto front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto &child : outAdj[front])
            {
                if (--out[child] == 0)
                    q.push(child);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};