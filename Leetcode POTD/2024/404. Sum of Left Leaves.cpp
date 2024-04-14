// Problem Link :- https://leetcode.com/problems/sum-of-left-leaves/

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

    int sum = 0;

    void DFS (TreeNode* node, bool isLeft)
    {
        if (node == NULL)
            return;

        if (node->left == NULL && node->right == NULL)
        {
            if (isLeft)
                sum += node->val;

            return;
        }

        DFS(node->left, true);
        DFS(node->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        DFS(root, false);
        return sum;
    }
};



class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        
        if (root == NULL) 
            return 0;
            
        if (root->left == NULL && root->right == NULL) 
            return isLeft ? root->val : 0;

        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};



class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root) {
        
        if (root == NULL) 
            return 0;
        
        int sum = 0;
        
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) 
            sum += root->left->val;

        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};



// Solved by BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        
        int sum = 0;
        
        queue<pair<TreeNode*, bool>> q;
        q.emplace(root, false);
        
        while (!q.empty())
        {
            TreeNode* node = q.front().first;
            bool isLeft = q.front().second;
            q.pop();
            
            if (node == NULL)
                continue;
            
            if (node->left == NULL && node->right == NULL && isLeft)
                sum += node->val;
            
            q.emplace(node->left, true);
            q.emplace(node->right, false);
        }
        
        return sum;
    }
};



// Solved by Morris Traversal
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum = 0;
        
        while (root)
        {
            if (root->left == NULL)
            {
                root = root->right;
                continue;
            }
            
            TreeNode* leftNode = root->left;
            
            while (leftNode->right && leftNode->right != root)
                leftNode = leftNode->right;
            
            if (leftNode->right == NULL)
            {
                leftNode->right = root;
                root = root->left;
            }
            
            else
            {
                if (leftNode == root->left && leftNode->left == NULL)
                    sum += leftNode->val;
                
                leftNode->right = NULL;
                root = root->right;
            }
        }
        
        return sum;
    }
};