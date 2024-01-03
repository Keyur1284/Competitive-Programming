// Problem Link :- https://leetcode.com/problems/find-mode-in-binary-search-tree/

// Solved by Inorder Traversal
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
    int maxStreak = 0, currStreak = 0, currNum = 0;
    
    vector<int> findMode(TreeNode* root) {
        
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* node) {
        
        if (node == NULL)
            return;

        dfs(node->left);
        
        int num = node->val;

        if (num == currNum)
            currStreak++;
        
        else
        {
            currStreak = 1;
            currNum = num;
        }

        if (currStreak > maxStreak) 
        {
            ans = {};
            maxStreak = currStreak;
        }

        if (currStreak == maxStreak) {
            ans.push_back(num);
        }

        dfs(node->right);
    }
};