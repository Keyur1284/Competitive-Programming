// Problem Link :- https://leetcode.com/problems/count-complete-tree-nodes/

// Solved by normal DFS (Less Optimized)
// Time Complexity : O(N)
// Space Complexity : O(N)

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
    
    int count = 0;

    void DFS (TreeNode* node)
    {
        if (node == NULL)
            return;

        count++;

        DFS (node->left);
        DFS (node->right);
    }

    int countNodes(TreeNode* root) {
        
        DFS (root);
        return count;
    }
};



// Optimized Solution
// Time Complexity : O(logN * logN)
// Space Complexity : O(logN)


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

    int findLeftHeight (TreeNode* node)
    {
        int height = 0;

        while (node)
        {
            height++;
            node = node->left;
        }

        return height;
    }

    int findRightHeight (TreeNode* node)
    {
        int height = 0;

        while (node)
        {
            height++;
            node = node->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {
        
        if (root == NULL)
            return 0;

        int leftHeight = findLeftHeight (root);
        int rightHeight = findRightHeight (root);

        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;

        else
            return 1 + countNodes (root->left) + countNodes (root->right);
    }
};