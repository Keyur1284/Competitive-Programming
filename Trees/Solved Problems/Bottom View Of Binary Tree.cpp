// Problem Link :- https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110

// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.emplace(root, 0);

    while (!q.empty())
    {
        BinaryTreeNode<int>* node = q.front().first;
        int line = q.front().second;
        q.pop();

        mp[line] = node->data;

        if (node->left)
            q.emplace(node->left, line - 1);

        if (node->right)
            q.emplace(node->right, line + 1);
    }
    
    for (auto &it : mp)
        ans.emplace_back(it.second);

    return ans;
}
