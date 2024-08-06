/*

    Leetcode guide :-  https://leetcode.com/discuss/general-discussion/1072418/Disjoint-Set-Union-(DSU)Union-Find-A-Complete-Guide


*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU
{

    vector<int> parent, rank, size;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int ultimateParentOf_U = findParent(u);
        int ultimateParentOf_V = findParent(v);

        if (ultimateParentOf_V == ultimateParentOf_U)
            return;
        if (rank[ultimateParentOf_U] < rank[ultimateParentOf_V])
        {
            parent[ultimateParentOf_U] = v;
        }
        else if (rank[ultimateParentOf_U] > rank[ultimateParentOf_V])
        {
            parent[ultimateParentOf_V] = ultimateParentOf_U;
        }
        else
        {
            parent[ultimateParentOf_V] = ultimateParentOf_U;
            rank[ultimateParentOf_U]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultimateParentOf_U = findParent(u);
        int ultimateParentOf_V = findParent(v);

        if (ultimateParentOf_V == ultimateParentOf_U)
            return;

        if (size[ultimateParentOf_U] < size[ultimateParentOf_V])
        {
            parent[ultimateParentOf_U] = ultimateParentOf_V;
            size[ultimateParentOf_V] += size[ultimateParentOf_U];
        }
        else
        {
            parent[ultimateParentOf_V] = ultimateParentOf_U;
            size[ultimateParentOf_U] += size[ultimateParentOf_V];
        }
    }
};

int main()
{
    DSU dsu(7);
    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);
    dsu.unionBySize(5, 6);

    if (dsu.findParent(3) == dsu.findParent(7))
        cout << "3 and 7 are in same set\n";
    else
        cout << "3 and 7 are in different set\n";

    dsu.unionBySize(3, 7);

    if (dsu.findParent(3) == dsu.findParent(7))
        cout << "3 and 7 are in same set\n";
    else
        cout << "3 and 7 are in different set\n";

    return 0;
}
