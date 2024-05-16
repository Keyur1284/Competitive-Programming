// Problem Link :- https://leetcode.com/problems/evaluate-boolean-binary-tree/

// Solved by DFS
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
    bool evaluateTree(TreeNode* root) {
        
        if (root->left == NULL && root->right == NULL)
            return root->val;

        if (root->left == NULL)
            return evaluateTree(root->right);

        if (root->right == NULL)
            return evaluateTree(root->left);

        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        return (root->val == 2) ? (left || right) : (left && right);
    }
};



class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        
        if (root == NULL)
            return true;

        if (root->left == NULL && root->right == NULL)
            return root->val;

        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        return (root->val == 3) ? (left && right) : (left || right);
    }
};