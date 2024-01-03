// Problem Link :- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Solved by DFS + BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

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

    void DFS (TreeNode* node, TreeNode* par)
    {
        if (node == NULL)
            return;

        DFS (node->left, node);

        if (par != NULL)
            parent[node] = par;

        DFS (node->right, node);
    }

    bool isNotVis (TreeNode* node)
    {
        return (vis.find(node) == vis.end());
    }

    bool hasParent (TreeNode* node)
    {
        return (parent.find(node) != parent.end());
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        DFS (root, NULL);
        queue<TreeNode*> BFS;
        vector<int> nodeVals;

        BFS.emplace(target);
        vis.emplace(target);

        while (!BFS.empty() && k > 0)
        {
            int size = BFS.size();

            while (size--)
            {
                TreeNode* node = BFS.front();
                BFS.pop();

                if (node->left && isNotVis(node->left))
                {
                    BFS.emplace(node->left);
                    vis.emplace(node->left);
                }

                if (node->right && isNotVis(node->right))
                {
                    BFS.emplace(node->right);
                    vis.emplace(node->right);
                }

                if (hasParent(node) && isNotVis(parent[node]))
                {
                    BFS.emplace(parent[node]);
                    vis.emplace(parent[node]);
                }
            }

            k--;
        }

        while (!BFS.empty())
        {
            TreeNode* node = BFS.front();
            BFS.pop();

            nodeVals.emplace_back(node->val);
        }

        return nodeVals;
    }
};