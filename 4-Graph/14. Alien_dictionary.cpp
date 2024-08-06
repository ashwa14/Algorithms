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
    string findOrder(string dict[], int N, int K)
    {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> ind;

        for (int i = 0; i < N - 1; i++)
        {
            int j = 0;
            while (j < dict[i].length() and j < dict[i + 1].length() and dict[i][j] == dict[i + 1][j])
            {
                j++;
            }
            if (j < dict[i].length() and j < dict[i + 1].length())
            {
                adj[dict[i][j]].push_back(dict[i + 1][j]);
                ind[adj[i + 1][j]]++;
            }
        }

        queue<char> q;
        for (auto &x : ind)
        {
            if (x.second == 0)
                q.push(x.first);
        }

        string ans;

        while (q.size())
        {
            auto front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto &child : adj[front])
            {
                if (--ind[child] == 0)
                    q.push(child);
            }
        }
        return ans;
    }
};