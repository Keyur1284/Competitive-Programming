// Problem Link :- https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457

// Solved by Iterative Approach
// Time Complexity :- O(log_2 N)
// Space Complexity :- O(1)

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int floorInBST(TreeNode<int> * root, int X)
{
    int floor = -1;

    while (root)
    {
        if (root->val == X)
        {
            floor = root->val;
            return floor;
        }

        if (root->val > X)
            root = root->left;

        else
        {
            floor = root->val;
            root = root->right;
        }
    }

    return floor;
}


// Solved by Recursive Approach
// Time Complexity :- O(log_2 N)
// Space Complexity :- O(log_2 N)

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int floorInBST(TreeNode<int> * root, int X)
{
    if (root == NULL)
        return INT_MAX;

    if (root->val == X)
        return root->val;

    if (root->val > X)
        return floorInBST (root->left, X);

    int floor = floorInBST (root->right, X);

    return (floor <= X) ? floor : root->val;
}