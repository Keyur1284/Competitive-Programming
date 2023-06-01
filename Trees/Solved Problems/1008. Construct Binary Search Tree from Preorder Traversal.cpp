// Problem Link :- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// Solved by making inorder vector from the given preorder
// Time Complexity :- O(NlogN)
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

    int preIndex = 0;
    unordered_map<int, int> mp;

    TreeNode* buildTree (int start, int end, vector<int> &inorder, vector<int>& preorder)
    {
        if (start > end)
            return NULL;

        int rootVal = preorder[preIndex++];
        int pivot = mp[rootVal];
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree (start, pivot - 1, inorder, preorder);
        root->right = buildTree (pivot + 1, end, inorder, preorder);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int n = inorder.size();

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return buildTree (0, n - 1, inorder, preorder); 
    }
};


// Optimized Solution
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

    int preIndex = 0;

    TreeNode* buildTree (int upperBound, vector<int>& preorder)
    {
        if (preIndex == preorder.size() || preorder[preIndex] > upperBound)
            return NULL;

        TreeNode* root = new TreeNode (preorder[preIndex++]);
        root->left = buildTree (root->val, preorder);
        root->right = buildTree (upperBound, preorder);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
    
        return buildTree (1001, preorder); 
    }
};