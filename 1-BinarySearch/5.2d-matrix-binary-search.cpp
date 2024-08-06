#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}

/*
    https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1


for leetcode : The first integer of each row is greater than the last integer of the previous row.

    https://leetcode.com/problems/search-a-2d-matrix/
*/

bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    int i = 0, j = m - 1; // since row and col is sorted so first row  and last col combined make a sorted array and mid element of this array will be at (0,m-1)

    while (i >= 0 and j >= 0 and i < n and j < m)
    {
        if (matrix[i][j] == x)
            return true;

        if (matrix[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
