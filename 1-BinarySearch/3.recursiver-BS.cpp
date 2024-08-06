#include <bits/stdc++.h>
using namespace std;
#define ll long long

int recBinarySearch(vector<int> &nums, int x, int low, int high)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (nums[mid] == x)
        return mid;
    else if (nums[mid] > x)
    {
        return recBinarySearch(nums, x, low, mid - 1);
    }
    else
    {
        return recBinarySearch(nums, x, mid + 1, high);
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << recBinarySearch(nums, 4, 0, nums.size() - 1) << endl;
    return 0;
}