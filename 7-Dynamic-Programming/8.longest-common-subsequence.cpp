#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

class Solution
{
    int help(int n, int m, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (n < 0 or m < 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        int ans = 0;
        if (s1[n] == s2[m])
            ans = 1 + help(n - 1, m - 1, s1, s2, dp);
        else
        {
            int one = help(n - 1, m, s1, s2, dp);
            int two = help(n, m - 1, s1, s2, dp);
            ans = max(one, two);
        }
        return dp[n][m] = ans;
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m));
        // return help(n - 1, m - 1, text1, text2, dp);
        // tabulation
        // base case
        for (int j = 0; j < m; j++)
            if (text1[0] == text2[j])
                dp[0][j] = 1;
            else if (j >= 1)
                dp[0][j] = dp[0][j - 1];
        for (int i = 0; i < n; i++)
            if (text2[0] == text1[i])
                dp[i][0] = 1;
            else if (i >= 1)
                dp[i][0] = dp[i - 1][0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1;
                    dp[i][j] += dp[i - 1][j - 1];
                }
                else
                {
                    int one = dp[i - 1][j];
                    int two = dp[i][j - 1];
                    dp[i][j] = max(one, two);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

// a abca