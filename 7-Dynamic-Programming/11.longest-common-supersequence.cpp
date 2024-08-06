#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

class Solution
{
    /*
        brute  :-
        find LCS and add prefix, middle, suffix chars of both string which are not present in LCS in the same sequence as present in the original strings

        To solve such question create the dp table for small testcases and always initialize the dp array
        as dp[n+1][m+1] way to avoid the basecase checks.
    */
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = n, j = m;
        string str;
        while (i > 0 and j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                str.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] >= dp[i][j - 1])
                {
                    str.push_back(str1[i - 1]);
                    i--;
                }
                else
                {
                    str.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        while (i > 0)
        {
            str.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0)
            str.push_back(str2[j - 1]), j--;

        reverse(str.begin(), str.end());
        return str;
    }
};