#include <bits/stdc++.h>
using namespace std;
#define ll long long

// sort array of 0, 1, 2 only

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // Three Pointers
        /*
            from 0 to low-1  ----> all 0's
            from low to mid-1 ----> all 1's
            from mid to high  ---> UNSORTED part
            from high + 1 to n-1  ---> all 2's

        */
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) // untill the unsorted part is not sorted completely
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*

    1 0 2 2 1 0
    ^         ^
    L         H
    M

    Mid != 0 || 2
    Mid++

    1 0 2 2 1 0
    ^ ^       ^
    L M       H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 1 2 2 1 0
      ^ ^     ^
      L M     H

    Mid == 2
    Swap High and Mid
    High--

    0 1 0 2 1 2
      ^ ^   ^
      L M   H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 0 1 2 1 2
        ^ ^ ^
        L M H

    Mid == 2
    Swap High and Mid
    High--

    0 0 1 1 2 2
        ^ ^
        L M
          H

    Mid <= High is our exit case


*/