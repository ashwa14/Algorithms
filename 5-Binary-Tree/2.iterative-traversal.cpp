#include <bits/stdc++.h>
using namespace std;
#define ll long long

class TreeNode
{

public:
    int val = 0;
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

vector<int> inorder(TreeNode *root)
{
    if (!root)
        return {};
    vector<int> ans;
    // inorder : left root right
    stack<TreeNode *> st; // using stack to backtrack to parent from child
    while (true)
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                return ans;
            TreeNode *node = st.top(); // this will be the parent of root
            st.pop();
            ans.push_back(node->val);
            root = node;
            root = root->right;
        }
    }
    return ans;
}

vector<int> preorder(TreeNode *root)
{
    if (!root)
        return {};
    vector<int> ans;
    // inorder : left root right
    stack<TreeNode *> st; // storing all the nodes who are parent of some other nodes i.e all not NULL nodes
    st.push(root);

    while (st.size())
    {
        auto node = st.top();
        st.pop();
        ans.push_back(node->val);
        if (node->left)
        {
            st.push(node->left);
        }
        if (node->right)
        {
            st.push(node->right);
        }
    }
    return ans;
}

vector<int> postorder(TreeNode *root)
{
    if (!root)
        return {};
    vector<int> ans;
    // inorder : left root right
    stack<TreeNode *> stLeft, stRight; //


    while(true)
    {
        
    }

    return ans;
}
