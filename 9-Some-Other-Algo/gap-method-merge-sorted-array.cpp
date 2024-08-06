#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

class Solution
{
    void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2)
    {
        if (arr1[ind1] > arr2[ind2])
        {
            swap(arr1[ind1], arr2[ind2]);
        }
    }

public:
    void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
    {
        // len of the imaginary single array:
        int len = n + m;

        // Initial gap:
        int gap = (len / 2) + (len % 2);

        while (gap > 0)
        {
            // Place 2 pointers:
            int left = 0;
            int right = left + gap;
            while (right < len)
            {
                // case 1: left in arr1[]
                // and right in arr2[]:
                if (left < m && right >= m)
                {
                    swapIfGreater(arr1, arr2, left, right - n);
                }
                // case 2: both pointers in arr2[]:
                else if (left >= n)
                {
                    swapIfGreater(arr2, arr2, left - n, right - n);
                }
                // case 3: both pointers in arr1[]:
                else
                {
                    swapIfGreater(arr1, arr1, left, right);
                }
                left++, right++;
            }
            // break if iteration gap=1 is completed:
            if (gap == 1)
                break;

            // Otherwise, calculate new gap:
            gap = (gap / 2) + (gap % 2);
        }
    }
};