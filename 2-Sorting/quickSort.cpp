#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(nlogn)
    Space Complexity : O(1) + Recursion Stack space
*/

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        qs(arr, low, pivotIndex - 1);
        qs(arr, pivotIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    int n = arr.size();
    qs(arr, 0, n - 1);
    return arr;
}
