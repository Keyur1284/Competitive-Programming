// Problem Link :- https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

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

    int maxi = INT_MIN;

    int DFS (TreeNode* node)
    {
        if (node == NULL)
            return 0;

        int left = max(0, DFS(node->left));
        int right = max(0, DFS(node->right));

        maxi = max(maxi, node->val + left + right);

        return node->val +  max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        
        DFS(root);

        return maxi;
    }
};