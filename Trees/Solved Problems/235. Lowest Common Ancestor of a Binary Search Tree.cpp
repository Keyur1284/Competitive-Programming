// Problem Link :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Solved by Recursive Approach
// Time Complexity :- O(N)
// Space Complexity :- O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        return root;
    }
};



// Solved by Recursive Approach (Optimized)
// Time Complexity :- O(H)      H -> height of the BST
// Space Complexity :- O(H)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL)
            return NULL;

        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor (root->right, p, q);

        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor (root->left, p, q);

        return root;
    }
};



// Solved by Iterative Approach
// Time Complexity :- O(H)      H -> height of the BST
// Space Complexity :- O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root)
        {
            if (root->val < p->val && root->val < q->val)
                root = root->right;

            else if (root->val > p->val && root->val > q->val)
                root = root->left;
            
            else
                break;
        }

        return root;
    }
};
