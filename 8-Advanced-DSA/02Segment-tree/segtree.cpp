class NumArray
{
    vector<int> nums, segTree;
    int n;

public:
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        n = nums.size();
        segTree.resize(4 * n + 1);
        buildTree(nums, 0, 0, n - 1);
    }

    void update(int index, int val)
    {
        upd(nums, 0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(nums, 0, 0, n - 1, left, right);
    }

    int query(vector<int> &nums, int pos, int s, int e, int l, int r)
    {
        if (s >= l and e <= r)
            return segTree[pos];
        if (e < l or s > r)
            return 0;
        int mid = (s + e) / 2;
        return query(nums, 2 * pos + 1, s, mid, l, r) + query(nums, 2 * pos + 2, mid + 1, e, l, r);
    }

    void buildTree(vector<int> &nums, int pos, int s, int e)
    {
        if (s == e)
        {
            segTree[pos] = nums[s];
            return;
        }
        int mid = (s + e) / 2;
        buildTree(nums, 2 * pos + 1, s, mid);
        buildTree(nums, 2 * pos + 2, mid + 1, e);
        // for range s-e we will store the ans in index s in segTree
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }

    void upd(vector<int> &nums, int pos, int s, int e, int index, int val)
    {
        if (s == e && e == index)
        {
            segTree[pos] = val;
            return;
        }
        int mid = (s + e) / 2;
        if (index <= mid)
            upd(nums, 2 * pos + 1, s, mid, index, val);
        else
            upd(nums, 2 * pos + 2, mid + 1, e, index, val);
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }
};

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    return 0;
}