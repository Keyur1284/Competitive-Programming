// Problem Link :- https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

// Time Complexity :- O(N)
// Space Complexity :- O(N)

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

    int startVal;
    TreeNode* startNode = NULL;

    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> vis;

    void findPar (TreeNode* node, TreeNode* par)
    {
        if (node == NULL)
            return;

        if (par)
            parent[node] = par;

        if (node->val == startVal)
            startNode = node;

        findPar (node->left, node);
        findPar (node->right, node);
    }

    int amountOfTime(TreeNode* root, int start) {
        
        this->startVal = start;

        findPar(root, NULL);

        queue<TreeNode*> BFS;
        BFS.emplace(startNode);
        vis.emplace(startNode);
        int time = 0;

        while (!BFS.empty())
        {
            int size = BFS.size();
            bool flag = false;

            while (size--)
            {
                TreeNode* node = BFS.front();
                BFS.pop();

                if (node->left && vis.find(node->left) == vis.end())
                {
                    flag = true;
                    BFS.emplace(node->left);
                    vis.emplace(node->left);
                }

                if (node->right && vis.find(node->right) == vis.end())
                {
                    flag = true;
                    BFS.emplace(node->right);
                    vis.emplace(node->right);
                }

                if (parent.find(node) != parent.end() && vis.find(parent[node]) == vis.end())
                {
                    flag = true;
                    BFS.emplace(parent[node]);
                    vis.emplace(parent[node]);
                }
            }

            if (flag)
                time++;
        }

        return time;
    }
};