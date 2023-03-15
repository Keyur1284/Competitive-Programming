// Problem Link :- https://leetcode.com/problems/check-completeness-of-a-binary-tree/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by BFS

// Solution :-  
// 1. Do a level order traversal of the tree.
// 2. If a node is NULL, set a flag to true.
// 3. If a node is not NULL and the flag is true, return false.
// 4. If a node is not NULL and the flag is false, push its left and right child to the queue.
// 5. If the traversal is complete, return true.


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
    bool isCompleteTree(TreeNode* root) {

        if (root == NULL)
            return true;

        bool nullFlag = false;

        queue<TreeNode*> q;
        q.emplace(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL)
                nullFlag = true;

            else
            {
                if (nullFlag)
                    return false;

                q.emplace(node->left);
                q.emplace(node->right);
            }
        }
        
        return true;
    }
};


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

    int countNodes(TreeNode* node)
    {
        if (node == NULL)
            return 0;

        int left = countNodes(node->left);
        int right = countNodes(node->right);

        return 1 + left + right;
    }

    bool DFS(TreeNode* node, int index, int totalNodes)
    {
        if (node == NULL)
            return true;

        if (index >= totalNodes)
            return false;

        bool left = DFS(node->left, 2 * index + 1, totalNodes);
        bool right = DFS(node->right, 2 * index + 2, totalNodes);

        return (left && right);
    }

    bool isCompleteTree(TreeNode* root) {

        if (root == NULL)
            return true;

        int totalNodes = countNodes(root);

        return DFS(root, 0, totalNodes);
    }
};