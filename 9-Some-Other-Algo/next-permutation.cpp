/*
    Codestory video : https://www.youtube.com/watch?v=CboKBIpo640
*/
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
    void nextPermutation(vector<int> &nums)
    {
        // Step 1 : Find the rightmost index i for which nums[i] < nums[i+1]
        // Step 2 : find the next greater element to nums[i] in the right side at some index j
        // Step 3 : swap i and j indexed elements
        // Step 4 : reverse i to n part of the array

        int n = nums.size();
        int i = n - 2; // not checking for n - 1 index since it doesn't has anything in it's right

        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = n - 1, val = INT_MAX, valIdx = -1;
        while (j > i)
        {
            if (nums[j] > nums[i] && nums[j] < val)
            {
                valIdx = j;
                val = nums[j];
            }
            j--;
        }

        swap(nums[valIdx], nums[i]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};