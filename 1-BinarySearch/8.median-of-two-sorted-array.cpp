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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // O(n) time and O(1) space solution

        int val1 = 0, val2 = 0, i = 0, j = 0, idx = 0;

        int size1 = nums1.size(), size2 = nums2.size();

        int size = size1 + size2;

        while (i < size1 or j < size2)
        {
            int element = -1;
            if (i < size1 and j < size2)
            {
                if (nums1[i] < nums2[j])
                {
                    element = nums1[i];
                    i++;
                }
                else
                {
                    element = nums2[j];
                    j++;
                }
            }
            else if (i < size1)
            {
                element = nums1[i];
                i++;
            }
            else
            {
                element = nums2[j];
                j++;
            }
            if (idx == size / 2)
            {
                val1 = element;
            }
            if (idx == size / 2 - 1)
            {
                val2 = element;
            }
            idx++;
        }
        if (size & 1)
        {
            return (double)val1;
        }
        return (val1 + val2) / 2.0;
    }
};

// TODO : Optmized Interview Approach
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Binary Search : O(log(size1 + size2)) time and constant space

        int size1 = nums1.size(), size2 = nums2.size();

        if (size1 > size2)
            return findMedianSortedArrays(nums2, nums1);

        if (size1 == 0)
        {
            if (size2 % 2 == 0)
            {
                return (nums2[size2 / 2] + nums2[size2 / 2 - 1]) / 2.0;
            }
            return nums2[size2 / 2];
        }

        int low = 0, high = size1;

        int leftPartSize = (size1 + size2 + 1) / 2;

        while (low <= high)
        {
            int mid1 = low + (high - low) / 2; // number of elements taken from nums1 for the left half
            int mid2 = leftPartSize - mid1;    // number of elements taken from nums2 for the left half
            // element from the left partition
            int left1 = INT_MIN, left2 = INT_MIN;
            // element from the right partition
            int right1 = INT_MAX, right2 = INT_MAX;

            if (mid1 > 0 && mid1 <= size1)
            {
                left1 = nums1[mid1 - 1];
            }
            if (mid2 > 0 && mid2 <= size2)
            {
                left2 = nums2[mid2 - 1];
            }
            if (size1 - mid1 >= 0 && mid1 < size1)
            {
                right1 = nums1[mid1];
            }
            if (size2 - mid2 >= 0 and mid2 < size2)
            {
                right2 = nums2[mid2];
            }

            if (left1 <= right2 and left2 <= right1)
            {
                if ((size1 + size2) & 1)
                    return max(left1, left2);
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else if (left1 > right2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};