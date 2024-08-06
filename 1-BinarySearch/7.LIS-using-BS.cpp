#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}
//! my approach:  working

class Solution
{
    bool valid(vector<int> &nums, int mid)
    {
        // temp array is representing not the actual LIS
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int lb = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[lb] = nums[i];
            }
        }
        return len >= mid;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        // USING Binary Search
        int n = nums.size();
        if (n <= 1)
            return n;
        int s = 1, e = n, res = 0;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (valid(nums, mid))
            {
                res = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return res;
    }
};
//! correct solution : https://takeuforward.org/data-structure/longest-increasing-subsequence-binary-search-dp-43/
int longestIncreasingSubsequence(int arr[], int n)
{

    vector<int> temp;
    temp.push_back(arr[0]);

    int len = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            // arr[i] > the last element of temp array

            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            // replacement step
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return len;
}
