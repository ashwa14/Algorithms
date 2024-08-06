#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

class Solution
{
public:
    set<string> st;

    void helper_print(string s, string t, int i, int j, string &temp, vector<string> &ans, int cnt)
    {
        if (cnt == 0)
        {
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                ans.push_back(temp);
            }
            return;
        }

        if (i >= s.size() || j >= t.size())
            return;

        for (int row = i; row < s.size(); row++)
        {
            for (int col = j; col < t.size(); col++)
            {
                if (s[row] == t[col])
                {
                    temp.push_back(s[row]);
                    helper_print(s, t, row + 1, col + 1, temp, ans, cnt - 1);
                    temp.pop_back();
                }
            }
        }
    }

    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        int dp[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcs_length = dp[n][m];

        vector<string> ans;

        string temp = "";

        helper_print(s, t, 0, 0, temp, ans, lcs_length);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
