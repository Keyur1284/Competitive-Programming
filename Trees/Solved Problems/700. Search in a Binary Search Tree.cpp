// Problem Link :- https://leetcode.com/problems/search-in-a-binary-search-tree/

// Solved by Recursive Approach
// Time Complexity :- O(log_2 N)
// Space Complexity :- O(log_2 N)

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
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root == NULL || root->val == val)
            return root;

        if (root->val < val)
            return searchBST (root->right, val);

        if (root->val > val)
            return searchBST (root->left, val);

        return NULL;  
    }
};


// Solved by Iterative Approach
// Time Complexity :- O(log_2 N)
// Space Complexity :- O(1)

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
    TreeNode* searchBST(TreeNode* root, int val) {

        while (root && root->val != val)
        {
            root = (root->val > val)? root->left : root->right;
        }

        return root;
    }
};