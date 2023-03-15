// Problem Link :- https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725

// Time Complexity :- O(H) + O(H) + O(N) = O(N)
// Space Complexity :- O(N)

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int>* node)
{
    return (node->left == NULL && node->right == NULL);
}

void leftBoundary (TreeNode<int>* root, vector<int> &ans)
{
    TreeNode<int>* node = root->left;

    while (node)
    {
        if(!isLeaf(node))
            ans.emplace_back(node->data);

        node = (node->left) ? node->left : node->right;
    }
}

void leafNodes (TreeNode<int>* root, vector<int> &ans)
{
    if (isLeaf(root)) 
    {
        ans.emplace_back(root->data);
        return;
    }

    if (root->left)
        leafNodes(root->left, ans);

    if (root->right)
        leafNodes(root->right, ans);
}

void rightBoundary (TreeNode<int>* root, vector<int> &ans)
{
    TreeNode<int>* node = root->right;
    stack<int> st;

    while (node)
    {
        if(!isLeaf(node))
            st.emplace(node->data);

        node = (node->right) ? node->right : node->left;
    }

    while (!st.empty())
    {
        ans.emplace_back(st.top());
        st.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    
    vector<int> ans;

    if (root == NULL)
        return ans;

    if(!isLeaf(root))
        ans.emplace_back(root->data);

    leftBoundary(root, ans);
    leafNodes(root, ans);
    rightBoundary(root, ans);

    return ans;
}