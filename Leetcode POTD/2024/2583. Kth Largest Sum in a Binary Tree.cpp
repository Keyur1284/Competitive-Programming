// Problem Link :- https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

// Solved by Level Order Traversal and Min Heap
// Time Complexity :- O(n * logk)
// Space Complexity :- O(n + k)

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        priority_queue<long long, vector<long long>, greater<long long>> levelSums;
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.emplace(node->left);

                if (node->right)
                    q.emplace(node->right);
            }

            levelSums.emplace(sum);

            if (levelSums.size() > k)
                levelSums.pop();
        }

        return levelSums.size() == k ? levelSums.top() : -1;
    }
};