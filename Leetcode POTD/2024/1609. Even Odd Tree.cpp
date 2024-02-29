// Problem Link :- https://leetcode.com/problems/even-odd-tree/

// Solved by BFS (Level Order Traversal)
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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> BFS;
        BFS.emplace(root);
        int level = 0;

        while (!BFS.empty())
        {
            int size = BFS.size();
            int prev = -1;

            while (size--)
            {
                auto node = BFS.front();
                BFS.pop();

                if (level & 1)
                {
                    if (node->val % 2 != 0)
                        return false;

                    else
                    {
                        if (prev == -1 || prev > node->val)
                            prev = node->val;

                        else
                            return false;
                    }
                }

                else
                {
                    if (node->val % 2 != 1)
                        return false;

                    else
                    {
                        if (prev == -1 || prev < node->val)
                            prev = node->val;

                        else
                            return false;
                    }
                }

                if (node->left)
                    BFS.emplace(node->left);

                if (node->right)
                    BFS.emplace(node->right);
            }

            level++;
        }

        return true;
    }
};



class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> BFS;
        BFS.emplace(root);
        int level = 0;

        while (!BFS.empty())
        {
            int size = BFS.size();
            int prev = -1;

            while (size--)
            {
                auto node = BFS.front();
                BFS.pop();

                if (node->val % 2 == level % 2)
                    return false;

                if (prev != -1)
                {
                    if (level % 2 == 0 && node->val <= prev)
                        return false;

                    if (level % 2 == 1 && node->val >= prev)
                        return false;
                }

                prev = node->val;

                if (node->left)
                    BFS.emplace(node->left);

                if (node->right)
                    BFS.emplace(node->right);
            }

            level++;
        }

        return true;
    }
};



// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    vector<int> prev;

    bool DFS(TreeNode* node, int level) 
    {
        if (node == NULL)
            return true;

        if (node->val % 2 == level % 2) 
            return false;

        if (prev.size() == level)
            prev.push_back(0);

        if (prev[level] != 0)
        {
            if (level % 2 == 0 && node->val <= prev[level])
                return false;

            if (level % 2 == 1 && node->val >= prev[level])
                return false;
        }

        prev[level] = node->val;

        bool left = DFS(node->left, level + 1);
        bool right = DFS(node->right, level + 1);

        return (left && right);
    }

    bool isEvenOddTree(TreeNode* root) {

        return DFS(root, 0);
    }
};