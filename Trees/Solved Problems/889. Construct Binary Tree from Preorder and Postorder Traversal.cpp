// Problem Link :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

// Time Complexity :- O(N)
// Space Complexity :- O(H)     H -> height of the tree

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
    
    int preIndex = 0, posIndex = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (root->val != postorder[posIndex])
            root->left = constructFromPrePost (preorder, postorder);

        if (root->val != postorder[posIndex])
            root->right = constructFromPrePost (preorder, postorder);

        posIndex++;

        return root;
    }
};