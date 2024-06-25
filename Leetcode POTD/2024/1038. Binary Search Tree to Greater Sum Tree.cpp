// Problem Link :- https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

// Solved by DFS (Reverse Inorder Traversal)
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

    void DFS(TreeNode* node, int &sum)
    {
        if (node == NULL)
            return;

        DFS(node->right, sum);
        sum += node->val;
        node->val = sum;
        DFS(node->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        
        int sum = 0;
        DFS(root, sum);
        return root;
    }
};



// Solved by Morris Traversal
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        
        int sum = 0;
        TreeNode* node = root;

        while (node) 
        {
            if (node->right == NULL) 
            {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }

            else 
            {
                TreeNode* succ = getSuccessor(node);

                if (succ->left == NULL) 
                {
                    succ->left = node;
                    node = node->right;
                }
                
                else 
                {
                    succ->left = NULL;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }

        return root;
    }

private:

    TreeNode* getSuccessor(TreeNode* node) {
        
        TreeNode* succ = node->right;
        
        while (succ->left && succ->left != node)
            succ = succ->left;
        
        return succ;
    }
};