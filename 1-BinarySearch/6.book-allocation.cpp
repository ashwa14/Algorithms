#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

bool check(int mid, int A[], int N, int M)
{
    // initializing cnt = 1 is imp (It took me one day to find the bug cuz I didn't dry ran it)
    int pages = 0, cnt = 1, i = 0;
    while (i < N)
    {
        pages += A[i];
        if (pages > mid)
        {
            pages = A[i];
            cnt++;
        }
        i++;
        if (cnt > M)
            return false;
    }
    return true;
}

// Function to find minimum number of pages.
int findPages(int A[], int N, int M)
{
    if (M > N)
        return -1;

    int sum = 0, maxi = -1e9;
    for (int i = 0; i < N; i++)
    {
        maxi = max(maxi, A[i]);
        sum += A[i];
    }

    int low = maxi, high = sum, ans = sum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (check(mid, A, N, M))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
