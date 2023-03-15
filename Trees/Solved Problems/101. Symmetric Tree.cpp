// Problem Link :- https://leetcode.com/problems/symmetric-tree/

// Time Complexity :- O(n)
// Space Complexity :- O(h), h -> height of the tree
// Best Case Space Complexity :- O(logn)
// Worst Case Space Complexity :- O(n)

// Recursive Solution

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL || right == NULL)
            return false;
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};


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

    bool isMirror(TreeNode* leftNode, TreeNode* rightNode)
    {
        if (leftNode == NULL && rightNode == NULL)
            return true;

        if (leftNode == NULL || rightNode == NULL || leftNode->val != rightNode->val)
            return false;

        return isMirror(leftNode->left, rightNode->right) && isMirror(leftNode->right, rightNode->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == NULL)
            return true;
        
        return isMirror(root->left, root->right);
    }
};


// Iterative Solution

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
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.emplace(root->left);
        q.emplace(root->right);

        while(!q.empty())
        {
            TreeNode* leftNode = q.front();
            q.pop();

            TreeNode* rightNode = q.front();
            q.pop();

            if (leftNode == NULL && rightNode == NULL)
                continue;

            if (leftNode == NULL || rightNode == NULL || leftNode->val != rightNode->val)
                return false;

            q.emplace(leftNode->left);
            q.emplace(rightNode->right);
            q.emplace(leftNode->right);
            q.emplace(rightNode->left);
        }

        return true;
    }
};