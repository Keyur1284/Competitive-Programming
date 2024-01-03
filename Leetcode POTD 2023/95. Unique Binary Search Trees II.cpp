// Problem Link :- https://leetcode.com/problems/unique-binary-search-trees-ii/

// Solved by DP
// Time Complexity :- O(4^n/(n ^ 0.5))
// Space Complexity :- O(4^n/(n ^ 0.5))

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

    vector<TreeNode*> buildTree (int start, int end, map<pair<int, int>, vector<TreeNode*>> &dp)
    {
        vector<TreeNode*> nodes;

        if (start > end)
        {
            nodes.emplace_back(nullptr);
            return nodes;
        }

        if (dp.find({start, end}) != dp.end())
            return dp[{start, end}];

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> left = buildTree (start, i - 1, dp);
            vector<TreeNode*> right = buildTree (i + 1, end, dp);

            for (auto &it : left)
            {
                for (auto &it2 : right)
                {
                    TreeNode* root = new TreeNode(i, it, it2);
                    nodes.emplace_back(root);
                }
            }
        }

        return dp[{start, end}] = nodes;
    }

    vector<TreeNode*> generateTrees(int n) {
        
        map<pair<int, int>, vector<TreeNode*>> dp;
        return buildTree(1, n, dp);
    }
};