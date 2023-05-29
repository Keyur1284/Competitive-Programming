// Problem Link :- https://leetcode.com/problems/same-tree/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by DFS

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
    
    bool DFS(TreeNode* tree1, TreeNode* tree2)
    {
        if (tree1 == NULL && tree2 == NULL)
            return true;

        if (tree1 == NULL || tree2 == NULL || tree1->val != tree2->val)
            return false;

        bool left = DFS(tree1->left, tree2->left);
        bool right = DFS(tree1->right, tree2->right);        

        return (left && right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return DFS(p, q);
    }
};


// Solved by BFS

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
    
    bool check(TreeNode* tree1, TreeNode* tree2)
    {
        if (tree1 == NULL && tree2 == NULL)
            return true;

        if (tree1 == NULL || tree2 == NULL || tree1->val != tree2->val)
            return false;

        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        queue<pair<TreeNode*, TreeNode*>> que;
        que.emplace(p, q);

        while (!que.empty())
        {
            TreeNode* tree1 = que.front().first;
            TreeNode* tree2 = que.front().second;
            que.pop();

            if (tree1 == NULL && tree2 == NULL)
                continue;

            if (!check(tree1, tree2))
                return false;

            que.emplace(tree1->left, tree2->left);
            que.emplace(tree1->right, tree2->right);
        }
        
        return true;
    }
};