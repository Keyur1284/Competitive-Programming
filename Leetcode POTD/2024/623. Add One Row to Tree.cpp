// Problem Link :- https://leetcode.com/problems/add-one-row-to-tree/

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

    void DFS(TreeNode* node, int &val, int depth)
    {
        if (node == NULL)
            return;

        if (depth == 1)
        {
            TreeNode* newLeft = new TreeNode(val);
            newLeft->left = node->left;
            node->left = newLeft;

            TreeNode* newRight = new TreeNode(val);
            newRight->right = node->right;
            node->right = newRight;

            return;
        }

        DFS(node->left, val, depth - 1);
        DFS(node->right, val, depth - 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if (depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        DFS(root, val, depth - 1);
        return root;
    }
};



// Solved by BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if (depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.emplace(root);
        depth--;

        while (!q.empty())
        {
            int n = q.size();
            
            if (depth == 1)
            {
                
                for (int i = 0; i < n; i++)
                {
                    TreeNode* node = q.front();
                    q.pop();

                    TreeNode* newLeft = new TreeNode(val);
                    newLeft->left = node->left;
                    node->left = newLeft;

                    TreeNode* newRight = new TreeNode(val);
                    newRight->right = node->right;
                    node->right = newRight;
                }
                
                break;
            }

            for (int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.emplace(node->left);

                if (node->right)
                    q.emplace(node->right);
            }

            depth--;
        }

        return root;
    }
};