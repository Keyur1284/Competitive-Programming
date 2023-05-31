// Problem Link :- https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if (root == NULL)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if (root->val > val)
            root->left = insertIntoBST (root->left, val);

        if (root->val < val)
            root->right = insertIntoBST (root->right, val);

        return root;
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if (root == NULL)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        TreeNode* curr = root;

        while (true)
        {
            if (curr->val <= val)
            {
                if (curr->right)
                    curr = curr->right;

                else
                {
                    curr->right = new TreeNode(val);
                    return root;
                }
            }

            else
            {
                if (curr->left)
                    curr = curr->left;

                else
                {
                    curr->left = new TreeNode(val);
                    return root;
                }
            }
        }
    }
};