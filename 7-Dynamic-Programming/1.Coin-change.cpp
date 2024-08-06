#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

class Solution
{

    /*Method - 1  O(n*amount/min(coins)) ~= O(n*k)

    int help(int amt, vector<int> &coins,  vector<int> &dp)
    {
        if (amt == 0) return 0;

        if (dp[amt] != -1) return dp[amt];

        int mini = 1e9;

        for (int i = 0; i < coins.size(); i++)
        {
            if (amt - coins[i] >= 0)
            {
                int pick = 1 + help(amt - coins[i],coins, dp);
                mini = min(pick, mini);
            }
        }

        return dp[amt] = mini;
    }
    */

    /*Method -2  O(n) */

    int help(int cur, int amt, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (cur < 0)
            return amt == 0 ? 0 : 1e9;
        if (amt == 0)
            return 0;

        if (dp[cur][amt] != -1)
            return dp[cur][amt];

        int pick = 1e9, noPick = 1e9;

        if (amt - coins[cur] >= 0)
        {
            pick = 1 + help(cur, amt - coins[cur], coins, dp);
        }
        noPick = help(cur - 1, amt, coins, dp);

        return dp[cur][amt] = min(pick, noPick);
    }

public:
    int coinChange(vector<int> &coins, int amt)
    {
        int n = coins.size();
        // vector<int> dp(amt + 1, -1);
        vector<vector<int>> dp(n, vector<int>(amt + 1));

        // int ans = help(n - 1, amt, coins, dp);

        /* 
        !Tabulation for Method-2
        */

        /*
        ! If we want to start the outer for loop from i=1, then write base case as follows
        ✨✨✨✨✨
                for (int i = 0; i <= amt; i++)
                {
                    if (i % coins[0] == 0)
                        dp[0][i] = i / coins[0];
                    else
                        dp[0][i] = 1e9;
                }
        */


        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= amt; j++)
            {
                int pick = 1e9, noPick = 1e9;
                if (j - coins[i] >= 0)
                {
                    pick = 1 + dp[i][j - coins[i]];
                }
                if (i > 0)
                    noPick = dp[i - 1][j];
                dp[i][j] = min(pick, noPick);
            }
        }

        return dp[n - 1][amt] >= 1e9 ? -1 : dp[n - 1][amt];
    }
};
