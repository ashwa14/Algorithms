
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    int i = 0, j = 0, curSum = 0;

    vector<int> nums = {1, 3, 4, 5, 6, 9};
    int n = nums.size();

    int target = 10, ans = 0;

    // longest subarray with sum equal to target in O(1) space and O(n) time

    while (i < n && j < n)
    {
        curSum += nums[j];
        while (i < n && curSum > target)
        {
            curSum -= nums[i];
            i++;
        }
        if (curSum == target)
        {
            ans = max(ans, j - i + 1);
        }
        j++;
    }

    return 0;
}