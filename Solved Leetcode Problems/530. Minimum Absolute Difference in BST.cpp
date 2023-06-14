// Problem Link :- https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Note :- This question is the same as 783. Minimum Distance Between BST Nodes
// Problem Link :- https://leetcode.com/problems/minimum-distance-between-bst-nodes/

// Solved by Inorder Traversal
// Time Complexity : O(n)
// Space Complexity : O(n)

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

    int mini = INT_MAX;
    TreeNode* prev = NULL;

    void inorder (TreeNode* node)
    {
        if (node == NULL)
            return;

        inorder (node->left);

        if (prev)
            mini = min(mini, node->val - prev->val);

        prev = node;

        inorder (node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        
        inorder (root);
        return mini;
    }
};