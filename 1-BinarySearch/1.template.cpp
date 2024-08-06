#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
int low = 0, high = val;
while (low < high)  // no <=  to avoid infinite loop
{
    int mid = low + (high - low) / 2;
    int totalCost = do some calculation
    if (totalCost <= money)
    {
        low = mid + 1; /
    }
    else
    {
        high = mid;  //no mid -1 because mid-1 is possible
    }
}
ans = low - 1;  // low-1 because low is the first value that is not possible
*/

//! You use while (start <= end) if you are returning the match from inside the loop.

//! You use while (start < end) if you want to exit out of the loop first, and then use the result of start or end to return the match.

//* best template for most of the bs on ans question

#define MAX_POSSIBLE_ANS 1 // some value

bool isValid(int n);

int solve(vector<int> &nums)
{
    int s = 0, e = MAX_POSSIBLE_ANS;
    int ans = 0;
    while (s <= e)
    {
        int middleAns = s + (e - s) / 2;
        if (isValid(middleAns))
        {
            ans = middleAns;
            s = middleAns + 1; // or middleAns - 1; depends upon problem
        }
        else
        {
            e = middleAns - 1; // or middleAns - 1;
        }
    }
    return ans;
}

/*
Book Allocation Problem (GFG)
Aggressive cow (spoj)
Prata and roti (spoj)
EKO (spoj)
Google kickstart A Q-3 2020
+ Painter Partition Problem

1482 Minimum Number of Days to Make m Bouquets
1283 Find the Smallest Divisor Given a Threshold
1231 Divide Chocolate
1011 Capacity To Ship Packages In N Days
875 Koko Eating Bananas  : done
Minimize
774 Max Distance to Gas Station
410 Split Array Largest Sum

*/