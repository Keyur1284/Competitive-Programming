// Problem Link :- https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Solved by BFS
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
    int minDepth(TreeNode* root) {
        
        if (root == NULL)
            return 0;

        queue<TreeNode*> BFS;
        BFS.emplace(root);
        int depth = 1;

        while (!BFS.empty())
        {
            int size = BFS.size();

            while (size--)
            {
                TreeNode* node = BFS.front();
                BFS.pop();

                if (node->left == NULL && node->right == NULL)
                    return depth;

                if (node->left)
                    BFS.emplace(node->left);

                if (node->right)
                    BFS.emplace(node->right);
            }

            depth++;
        }

        return 0;
    }
};



// Solved by DFS
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
    int minDepth(TreeNode* root) {
        
        if (root == NULL)
            return 0;

        if (root->left == NULL)
            return 1 + minDepth(root->right);

        if (root->right == NULL)
            return 1 + minDepth(root->left);

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return 1 + min(left, right);
    }
};