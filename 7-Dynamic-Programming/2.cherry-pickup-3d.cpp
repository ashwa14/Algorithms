#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

/*
https://leetcode.com/problems/cherry-pickup-ii/
*/

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        dp[0][n - 1] = grid[0][0] + grid[0][n - 1];

        for (int i = 1; i < m; i++)
        {
            vector<vector<int>> cur(n, vector<int>(n, -1));
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    int maxLast = -1;
                    for (int x = -1; x <= 1; x++)
                    {
                        for (int y = -1; y <= 1; y++)
                        {
                            if (j + x >= 0 and j + x < n and k + y >= 0 and k + y < n)
                                maxLast = max(maxLast, dp[j + x][k + y]);
                        }
                    }
                    if (maxLast == -1)
                        continue;
                    if (j == k)
                        cur[j][k] = grid[i][j] + maxLast;
                    else
                        cur[j][k] = grid[i][j] + grid[i][k] + maxLast;
                }
            }
            dp = cur;
        }

        int ans = 0;

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans = max(ans, dp[j][k]);
            }
        }
        return ans;
    }
};