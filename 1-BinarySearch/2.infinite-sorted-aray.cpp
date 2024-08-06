#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

int findElement(vector<int> &nums, int target)
{
    // assume that nums is an infinite sorted array

    int low = 0, high = 1;

    while (nums[high] < target)
    {
        low = high + 1;
        high *= 2;
    }

    // once we got the finite search space in which target might present apply simple binary search
}

int main()
{
    return 0;
}