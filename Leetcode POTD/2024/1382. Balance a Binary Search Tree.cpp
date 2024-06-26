// Problem Link :- https://leetcode.com/problems/balance-a-binary-search-tree/

// Solved by Sorting Vals
// Time Complexity :- O(nlogn)
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

    void inorder(TreeNode* node, vector<int> &vals)
    {
        if (node == NULL)
            return;

        inorder(node->left, vals);
        vals.emplace_back(node->val);
        inorder(node->right, vals);
    }

    TreeNode* buildTree(int left, int right, vector<int> &vals)
    {
        if (left > right)
            return NULL;

        int mid = (left + right) >> 1;
        TreeNode* root = new TreeNode(vals[mid]);
        root->left = buildTree(left, mid - 1, vals);
        root->right = buildTree(mid + 1, right, vals);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> vals;

        inorder(root, vals);
        sort(vals.begin(), vals.end());
        int n = vals.size();

        return buildTree(0, n - 1, vals);
    }
};