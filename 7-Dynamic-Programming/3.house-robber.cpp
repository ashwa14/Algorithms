//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{

    int help(int cur, int *arr, int n, vector<int> &dp)
    {
        if (cur < 0)
            return 0;

        if (dp[cur] != -1)
            return dp[cur];

        int maxSum = -1e9;

        int pick = arr[cur] + help(cur - 2, arr, n, dp);
        int noPick = help(cur - 1, arr, n, dp);
        maxSum = max({maxSum, pick, noPick});

        return dp[cur] = maxSum;
    }

public:
/*
!  You can only pickup coins from alternate houses. No adjacent houses can be picked.
*/
    int findMaxSum(int *arr, int n)
    {
        if (n == 1)
            return arr[0];
        int prev = max(arr[0], arr[1]), prev2 = arr[0], ans = 0;
        if (n == 2)
            return prev;

        /* 
            * Space Optimized iterative O(n) time and O(1) space
        */

        for (int i = 2; i < n; i++)
        {
            int pick = arr[i] + prev2;
            int noPick = prev;
            ans = max(pick, noPick);
            prev2 = prev;
            prev = ans;
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends