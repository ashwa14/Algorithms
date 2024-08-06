#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int help(int cur, int w, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (cur < 0)
            return 0;

        if (dp[cur][w] != -1)
            return dp[cur][w];

        int pick = 0, noPick = 0;

        if (wt[cur] <= w)
            pick = val[cur] + help(cur - 1, w - wt[cur], val, wt, dp);

        noPick = help(cur - 1, w, val, wt, dp);

        return dp[cur][w] = max(pick, noPick);
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1));

        // we can only pick when required weight is greater than w[i] (think in physical scenario)
        // and whatever be the weight we can't get more value than val[0] for 0th index.

        for (int i = wt[0]; i <= W; i++)
            dp[0][i] = val[0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                int pick = 0, noPick = 0;
                // we can only pick when required weight is greater than w[i] (think in physical scenario)
                if (wt[i] <= j)
                    pick = val[i] + dp[i - 1][j - wt[i]];
                noPick = dp[i - 1][j];
                dp[i][j] = max(pick, noPick);
            }
        }
        return dp[n - 1][W];
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends