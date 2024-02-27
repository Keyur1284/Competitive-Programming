// Problem Link :- https://leetcode.com/problems/diameter-of-binary-tree/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

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

    int maxi = 0;

    int DFS (TreeNode* node)
    {
        if (node == NULL)
            return 0;

        int left = DFS(node->left);
        int right = DFS(node->right);

        maxi = max(maxi, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        DFS(root);

        return maxi;
    }
};
