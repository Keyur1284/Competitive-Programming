// Problem Link :- https://leetcode.com/problems/all-possible-full-binary-trees/

// Solved by DP
// Time Complexity :- O(2^(n/2))
// Space Complexity :- O(n * 2^(n/2))

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
    
    unordered_map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if (n % 2 == 0)
            return {};

        if (n == 1)
            return {new TreeNode()};

        if (dp.find(n) != dp.end())
            return dp[n];

        vector<TreeNode*> ans;

        for (int i = 1; i < n; i++)
        {
            vector<TreeNode*> left = allPossibleFBT (i);
            vector<TreeNode*> right = allPossibleFBT (n - i - 1);

            for (auto &l : left)
            {
                for (auto &r : right)
                {
                    TreeNode* node = new TreeNode(0, l, r);
                    ans.emplace_back(node);
                }
            }
        }

        return dp[n] = ans;
    }
};