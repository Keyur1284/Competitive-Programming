// Problem Link :- https://leetcode.com/problems/recover-binary-search-tree/

// Solved by doing inorder traversal
// Time Complexity :- O(NlogN)
// Space Complexity :- O(N)

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

    int inIndex = 0;
    vector<int> inorder;

    void inorderTraversal (TreeNode* node)
    {
        if (node == NULL)
            return;

        inorderTraversal (node->left);
        inorder.emplace_back(node->val);
        inorderTraversal (node->right);
    }

    void recovering (TreeNode* node)
    {
        if (node == NULL)
            return;

        recovering (node->left);
        node->val = inorder[inIndex++];
        recovering (node->right);
    }

    void recoverTree(TreeNode* root) {
        
        inorderTraversal (root);
        sort(inorder.begin(), inorder.end());

        recovering (root);
    }
};


// Optimized Solution
// Time Complexity :- O(N)
// Space Complexity :- O(1)


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

    TreeNode *prev, *firstViolation = NULL, *secondViolation = NULL, *middle = NULL;

    void inorder (TreeNode* node)
    {
        if (node == NULL)
            return;

        inorder (node->left);

        if (node->val < prev->val)
        {
            if (firstViolation == NULL)
            {
                firstViolation = prev;
                middle = node;
            }

            else
                secondViolation = node;
        }

        prev = node;

        inorder (node->right);
    }

    void recoverTree(TreeNode* root) {
        
        prev = new TreeNode(INT_MIN);
        inorder (root);

        (firstViolation && secondViolation) ? swap (firstViolation->val, secondViolation->val) : swap (firstViolation->val, middle->val);
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

    TreeNode *prev, *firstViolation = NULL, *secondViolation = NULL;

    void inorder (TreeNode* node)
    {
        if (node == NULL)
            return;

        inorder (node->left);

        if (node->val < prev->val)
        {
            if (firstViolation == NULL)
            {
                firstViolation = prev;
                secondViolation = node;
            }

            else
                secondViolation = node;
        }

        prev = node;

        inorder (node->right);
    }

    void recoverTree(TreeNode* root) {
        
        prev = new TreeNode(INT_MIN);
        inorder (root);

        swap (firstViolation->val, secondViolation->val);
    }
};