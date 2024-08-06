
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int help(int cur, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (cur < 0 or W <= 0)
            return 0;

        if (dp[cur][W] != -1)
            return dp[cur][W];
        int pick = 0, noPick = 0;

        if (W - wt[cur] >= 0)
        {
            pick = val[cur] + help(cur, W - wt[cur], val, wt, dp);
        }
        noPick = help(cur - 1, W, val, wt, dp);

        return dp[cur][W] = max(pick, noPick);
    }

public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1));
        // Tabulation
        // base case
        //? why we are multiplying with (i/wt[0]) ?  because we can pick same item multiple times

        for (int i = wt[0]; i <= W; i++)
            dp[0][i] = (i / wt[0]) * val[0];

        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                int pick = 0, noPick = 0;
                if (j - wt[i] >= 0)
                    pick = val[i] + dp[i][j - wt[i]];
                noPick = dp[i - 1][j];
                dp[i][j] = max(pick, noPick);
            }
        }

        /* // base case inside main for loop itself
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<=W;j++)
                {
                    int pick = 0, noPick = 0;
                    if(j-wt[i]>=0)
                        pick = val[i] + dp[i][j-wt[i]];
                    if(i>=1)
                        noPick = dp[i-1][j];
                    else noPick = 0;
                    dp[i][j] = max(pick,noPick);
                }
            }
        */
        return dp[N - 1][W];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends