// Problem Link :- https://leetcode.com/problems/balanced-binary-tree/

// Time Complexity :- O(n)
// Space Complexity :- O(h), h -> height of tree

// Solved by DFS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int DFS (TreeNode* node)
    {
        if (node == NULL)
            return 0;

        int left = DFS(node->left);

        if (left == -1)
            return -1;

        int right = DFS(node->right);

        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        
        return (DFS(root) != -1);
    }
};


