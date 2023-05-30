// Problem Link :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

    TreeNode* buildTreeHelper(int start, int end, int &preIndex, vector<int>& preorder, vector<int>& inorder, unordered_map <int, int> &mp)
    {
        if (start > end)
            return NULL;

        int rootValue = preorder[preIndex++];
        int pivot = mp[rootValue];

        TreeNode* root = new TreeNode(rootValue);
        root->left = buildTreeHelper(start, pivot - 1, preIndex, preorder, inorder, mp);
        root->right = buildTreeHelper(pivot + 1, end, preIndex, preorder, inorder, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map <int, int> mp;
        int n = inorder.size();
        int preIndex = 0;

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return buildTreeHelper (0, n - 1, preIndex, preorder, inorder, mp);
    }
};