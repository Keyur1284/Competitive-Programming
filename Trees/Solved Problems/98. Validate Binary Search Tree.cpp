// Problem Link :- https://leetcode.com/problems/validate-binary-search-tree/

// Time Complexity :- O(N)
// Space Complexity :- O(N)

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

    bool checkBST (TreeNode* node, long mini, long maxi)
    {
        if (node == NULL)
            return true;

        if (node->val <= mini || node->val >= maxi)
            return false;
        
        return checkBST (node->left, mini, node->val) & checkBST (node->right, node->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        
        long mini = LONG_MIN, maxi = LONG_MAX;
        
        return checkBST (root, mini, maxi);
    }
};