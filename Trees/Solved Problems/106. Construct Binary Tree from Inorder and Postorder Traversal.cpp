// Problem Link :- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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

    unordered_map<int, int> mp;

    TreeNode* buildTreeHelper (int start, int end, int &postIndex, vector<int>& inorder, vector<int>& postorder)
    {
        if (start > end)
            return NULL;

        int rootValue = postorder[postIndex--];
        int pivot = mp[rootValue];

        TreeNode* root = new TreeNode(rootValue);
        root->right = buildTreeHelper(pivot + 1, end, postIndex, inorder, postorder);
        root->left = buildTreeHelper(start, pivot - 1, postIndex, inorder, postorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();

        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }

        int postIndex = n - 1;

        return buildTreeHelper (0, n - 1, postIndex, inorder, postorder);
    }
};