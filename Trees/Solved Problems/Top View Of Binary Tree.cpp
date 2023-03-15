// Problem Link :- https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401

// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<TreeNode<int>*, int>> q;
    q.emplace(root, 0);

    while (!q.empty())
    {
        TreeNode<int>* node = q.front().first;
        int line = q.front().second;
        q.pop();

        if (mp.find(line) == mp.end())
            mp[line] = node->val;

        if (node->left)
            q.emplace(node->left, line - 1);

        if (node->right)
            q.emplace(node->right, line + 1);
    }

    for (auto &it : mp)
        ans.emplace_back(it.second);

    return ans;
}