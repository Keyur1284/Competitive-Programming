// Problem Link :- https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            while (size--)
            {
                TreeNode* node = q.front();
                q.pop();

                level.emplace_back(node->val);

                if(node->left)
                    q.emplace(node->left);

                if(node->right)
                    q.emplace(node->right);
            }

            ans.emplace_back(level);
        }

        return ans;
    }
};