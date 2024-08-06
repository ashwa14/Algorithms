#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Majority Element > n/2
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // optimized
        int freq = 0, candidate = nums[0], n = nums.size();
        for (auto &x : nums)
        {
            if (x == candidate)
                freq++;
            else
                freq--;
            if (freq == 0)
                candidate = x, freq = 1;
        }
        return candidate;
    }
};

int main()
{
    return 0;
}
