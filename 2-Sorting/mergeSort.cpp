#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<int> &arr, int s, int mid, int e)
{
    int i = s, j = mid + 1;
    vector<int> temp;
    while (i <= mid or j <= e)
    {
        if (i <= mid and j <= e)
        {
            if (arr[i] > arr[j])
            {
                temp.push_back(arr[j]);
                j++;
            }
            else
            {
                temp.push_back((arr[i]));
                i++;
            }
        }
        else if (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    for (int i = 0; i < temp.size(); i++)
        arr[i + s] = temp[i];
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main()
{

    vector<int> arr = {4, 2, 1, 3, 5, 6, 11, 8, 9, 10};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}
