// Problem Link :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Solved by finding path to each node
// Time Complexity :- O(n)
// Space Complexity :- O(n)

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

    bool findPath (TreeNode* root, TreeNode* node, vector<int> &path)
    {
        if (root == NULL)
            return false;

        path.emplace_back(root->val);

        if (path.back() == node->val)
            return true;

        bool left = findPath (root->left, node, path);
        bool right = findPath (root->right, node, path);

        if (left || right)
            return true;

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<int> path1, path2;

        findPath (root, p, path1);
        findPath (root, q, path2);

        int size = min(path1.size(), path2.size()), i = 0;

        for (i = 0; i < size; i++)
        {
            if (path1[i] == path2[i])
                continue;

            break;
        }

        return new TreeNode(path1[i - 1]);
    }
};


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