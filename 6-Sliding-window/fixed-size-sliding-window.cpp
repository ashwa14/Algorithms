#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<int> nums = {1, 3, 4, 5, 6, 9};
    int n = nums.size();

    // maximum sum subarray with size k

    int i = 0, j = 0, k = 3;

    int sum = 0, maxSum = 0;

    while (j < n)
    {
        sum += nums[j];
        while (j - i + 1 > k)
        {
            sum -= nums[i];
            i++;
        }

        if (j - i + 1 == k)
        {
            maxSum = max(maxSum, sum);
        }

        j++;
    }

    return 0;
}