#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}
class Solution
{
    /*Backtracking gives obvious TLE 40/65 TC passed
        int help(int cur, string &temp, string &s, string &t)
        {
            if (cur >= s.size())
                return temp == t;

            temp.push_back(s[cur]);
            int one = help(cur + 1, temp, s, t);
            temp.pop_back();
            int two = help(cur + 1, temp, s, t);
            return one + two;
        }
    */

    // tle 50/65 tc passed
    void helper(string s, string t, int i, int j, string &temp, map<string, int> &mp, int count)
    {

        if (count == 0)
        {
            mp[temp]++;
            return;
        }
        if (i >= s.size() || j >= t.size())
            return;

        for (int r = i; r < s.size(); r++)
        {
            for (int c = j; c < t.size(); c++)
            {
                if (s[r] == t[c])
                {

                    temp.push_back(s[r]);
                    helper(s, t, r + 1, c + 1, temp, mp, count - 1);
                    temp.pop_back();
                }
            }
        }
    }

    // optimized solution
    // 65/65 tc passed

public:
    int numDistinct(string s, string t)
    {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        // count all possible lcs :- print them
        map<string, int> mp;
        int len = dp[n][m];
        string temp;
        helper(s, t, 0, 0, temp, mp, len);
        return mp[t];
    }
};