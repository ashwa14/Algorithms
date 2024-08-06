#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans = 0;

public:
    int help(int n, int m, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (n < 0 or m < 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        int pick = 0, one = 0, two = 0;
        if (s1[n] == s2[m])
            pick = 1 + help(n - 1, m - 1, s1, s2, dp);
        one = help(n - 1, m, s1, s2, dp);
        two = help(n, m - 1, s1, s2, dp);
        ans = max(ans, pick);
        return dp[n][m] = pick;
    }

    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m));
        // help(n - 1, m - 1, s1, s2, dp);

        // tabulation
            
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = 1;
                    if (i >= 1 and j >= 1)
                        dp[i][j] += dp[i - 1][j - 1];
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}

// } Driver Code Ends