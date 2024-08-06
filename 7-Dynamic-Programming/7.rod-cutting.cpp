#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int help(int cur, int len, int price[], vector<vector<int>> &dp)
    {
        if (cur < 0 or len <= 0)
            return 0;
        if (dp[cur][len] != -1)
            return dp[cur][len];
        int pick = 0, noPick = 0;
        if (len - cur - 1 >= 0)
            pick = price[cur] + help(cur, len - cur - 1, price, dp);
        noPick = help(cur - 1, len, price, dp);
        return dp[cur][len] = max(pick, noPick);
    }

public:
    int cutRod(int price[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1));

        // return help(n-1,n,price,dp);
        // Tabulation

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int pick = 0, noPick = 0;
                if (j - i - 1 >= 0)
                    pick = price[i] + dp[i][j - i - 1];
                if (i >= 1)
                    noPick = dp[i - 1][j];
                dp[i][j] = max(pick, noPick);
            }
        }
        /* separately written base case

            for (int j = 1; j <= n; j++)
                    dp[0][j] = price[0] * (j);

            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    int pick = 0, noPick = 0;
                    if (j - i - 1 >= 0)
                        pick = price[i] + dp[i][j - i - 1];
                    if (i >= 1)
                        noPick = dp[i - 1][j];
                    dp[i][j] = max(pick, noPick);
                }
            }
        */
        return dp[n - 1][n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
