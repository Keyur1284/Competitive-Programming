// Problem Link :- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Time Complexity :- O(N)
// Space Complexity :- O(N)

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

    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> vis;

    void findPar (TreeNode* node, TreeNode* par)
    {
        if (node == NULL)
            return;

        if (par)
        parent[node] = par;

        findPar (node->left, node);
        findPar (node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        findPar (root, NULL);

        queue<TreeNode*> BFS;
        BFS.emplace(target);
        vis.emplace(target);

        while (k > 0 && !BFS.empty())
        {
            int size = BFS.size();

            while (size--)
            {
                TreeNode* node = BFS.front();
                BFS.pop();

                if (node->left && vis.find(node->left) == vis.end())
                {
                    BFS.emplace(node->left);
                    vis.emplace(node->left);
                }

                if (node->right && vis.find(node->right) == vis.end())
                {
                    BFS.emplace(node->right);
                    vis.emplace(node->right);
                }

                if (parent.find(node) != parent.end() && vis.find(parent[node]) == vis.end())
                {
                    BFS.emplace(parent[node]);
                    vis.emplace(parent[node]);
                }
            }

            k--;
        }

        vector<int> nodes;

        while (!BFS.empty())
        {
            TreeNode* node = BFS.front();
            BFS.pop();
            int data = node->val;
            nodes.emplace_back(data);
        }

        return nodes;
    }
};