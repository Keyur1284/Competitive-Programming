// Problem Link :- https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

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

    pair<int, int> DFS (TreeNode* node, int &ans)
    {
        if (node == NULL)
            return {0, 0};

        auto left = DFS (node->left, ans);
        auto right = DFS (node->right, ans);

        int sum = left.first + right.first + node->val;
        int nodes = left.second + right.second + 1;

        ans += (sum/nodes == node->val);

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        
        int ans = 0;
        DFS (root, ans);

        return ans;
    }
};