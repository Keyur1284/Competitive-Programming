// Problem Link :- https://leetcode.com/problems/binary-tree-postorder-traversal/

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

    vector<int> ans;

    void postOrder(TreeNode* root)
    {
        if (root == NULL)
            return;

        postOrder(root->left);
        postOrder(root->right);
        ans.emplace_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        
        postOrder(root);

        return ans;
    }
};