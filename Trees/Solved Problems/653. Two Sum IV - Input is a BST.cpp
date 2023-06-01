// Problem Link :- https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Time Complexity :- O(N)
// Space Complexity :- O(H)     H -> height of BST

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
    
    stack<TreeNode*> before, next;

    void pushNodes (TreeNode* node, bool flag)
    {
        while (node)
        {
            (flag) ? before.emplace(node) : next.emplace(node);
            node = (flag) ? node = node->right : node = node->left;;
        }
    }

    int popNode (bool flag)
    {
        TreeNode* node = (flag) ? before.top() : next.top();
        (flag) ? before.pop() : next.pop();
        pushNodes ((flag) ? node->left : node->right, flag);

        return node->val;
    }

    bool findTarget(TreeNode* root, int k) {
    
        pushNodes (root, false);
        pushNodes (root, true);

        int low = popNode (false);
        int high = popNode (true);

        while (low < high)
        {
            int sum = low + high;

            if (sum == k)
                return true;

            else if (sum > k)
                high = popNode (true);

            else if (sum < k)
                low = popNode (false);
        }

        return false;
    }
};