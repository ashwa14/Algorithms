//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
todo https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/
class Solution
{
    const int M = 1e9 + 7;

public:
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1));
        //   sort(arr,arr + n,greater<int>());
        /*
        ?
            if arr[i] == 0 then we need to count two subset one for an empty subset
         !   second for {0}. so use the += operation everywhere
        */
        dp[0][0] = 1;
        if (arr[0] <= sum)
            dp[0][arr[0]] += 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                int req = j - arr[i];
                if (req >= 0)
                    dp[i][j] += dp[i - 1][req];
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % M;
            }
        }
        return dp[n - 1][sum];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends