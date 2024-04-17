// Problem Link :- https://leetcode.com/problems/smallest-string-starting-from-leaf/

// Solved by DFS
// Time Complexity :- O(n + leafNodes * height)
// Space Complexity :- O(n + height)

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

    string smallestString;

    void DFS(TreeNode *node, string &path)
    {
        if (node == NULL)
            return;

        path += node->val + 'a';

        if (node->left == NULL && node->right == NULL)
        {
            reverse(path.begin(), path.end());

            if (smallestString.empty() || smallestString > path)
                smallestString = path;

            reverse(path.begin(), path.end());
        }

        else
        {
            DFS(node->left, path);
            DFS(node->right, path);
        }
        
        path.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        
        string path;
        DFS(root, path);

        return smallestString;
    }
};



// Solved by BFS
// Time Complexity :- O(n + leafNodes * height)
// Space Complexity :- O(n + height)

class Solution {
public:

    string smallestFromLeaf(TreeNode* root) {
        
        string smallestString;
        queue<pair<TreeNode*, string>> q;
        q.emplace(root, "");

        while (!q.empty())
        {
            auto [node, path] = q.front();
            q.pop();

            path += node->val + 'a';

            if (node->left == NULL && node->right == NULL)
            {
                reverse(path.begin(), path.end());

                if (smallestString.empty() || smallestString > path)
                    smallestString = path;

                reverse(path.begin(), path.end());
            }

            if (node->left)
                q.emplace(node->left, path);

            if (node->right)
                q.emplace(node->right, path);
        }

        return smallestString;
    }
};