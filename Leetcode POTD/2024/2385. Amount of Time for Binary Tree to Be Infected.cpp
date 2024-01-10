// Problem Link :- https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

// Solved by DFS + BFS
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
private:
    
    int maxDistance = 0;

public:
    
    int amountOfTime(TreeNode* root, int start) 
    {
        DFS (root, start);
        return maxDistance;
    }

    int DFS (TreeNode* root, int start) 
    {
        int depth = 0;

        if (root == NULL)
            return depth;

        int leftDepth = DFS (root->left, start);
        int rightDepth = DFS (root->right, start);

        if (root->val == start) 
        {
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        } 
        
        else if (leftDepth >= 0 && rightDepth >= 0)
            depth = max(leftDepth, rightDepth) + 1;
        
        else 
        {
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }
};