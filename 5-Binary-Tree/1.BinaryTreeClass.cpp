#include <bits/stdc++.h>
using namespace std;
#define ll long long

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int val = 0)
    {
        this->val = val;
        left = right = NULL;
    }

    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

int main()
{
    return 0;
}