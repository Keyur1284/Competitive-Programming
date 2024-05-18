// Problem Link :- https://leetcode.com/problems/distribute-coins-in-binary-tree/

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

    int moves = 0;

    int DFS(TreeNode* node)
    {
        if (node == NULL)
            return 0;

        int leftMoves = DFS(node->left);
        int rightMoves = DFS(node->right);

        moves += abs(leftMoves) + abs(rightMoves);

        return node->val - 1 + leftMoves + rightMoves;
    }

    int distributeCoins(TreeNode* root) {
        
        DFS(root);
        return moves;
    }
};