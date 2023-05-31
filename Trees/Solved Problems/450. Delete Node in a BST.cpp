// Problem Link :- https://leetcode.com/problems/delete-node-in-a-bst/

// Time Complexity :- O(log_2 N)
// Space Complexity :- O(log_2 N)

// Best Solution 

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

    int height (TreeNode* node)
    {
        if (node == NULL)
            return 0;

        int left = height(node->left);
        int right = height(node->right);

        return 1 + max(left, right);
    }

    TreeNode* Successor (TreeNode* node)
    {
        while (node && node->left)
            node = node->left;

        return node;
    }

    TreeNode* Predecessor (TreeNode* node)
    {
        while (node && node->right)
            node = node->right;

        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == NULL || (root->val == key && root->left == NULL && root->right == NULL))
            return NULL;

        if (root->val < key)
            root->right = deleteNode (root->right, key);

        else if (root->val > key)
            root->left = deleteNode (root->left, key);

        else if (root->val == key)
        {
            if (height(root->right) > height(root->left))
            {
                TreeNode* temp = Successor(root->right);
                root->val = temp->val;
                root->right = deleteNode (root->right, temp->val);
            }

            else
            {
                TreeNode* temp = Predecessor(root->left);
                root->val = temp->val;
                root->left = deleteNode (root->left, temp->val);
            }
        }

        return root;
    }
};


// Solved by Striver's Method
// Time Complexity :- O(log_2 N)
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

    TreeNode* findLastRightChild (TreeNode* node)
    {
        while (node && node->right)
            node = node->right;

        return node;
    }

    TreeNode* helper (TreeNode* node)
    {
        if (node->left == NULL)
            return node->right;

        if (node->right == NULL)
            return node->left;

        TreeNode* rightChild = node->right;
        TreeNode* lastRightChild = findLastRightChild (node->left);
        lastRightChild->right = rightChild;
        return node->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == NULL)
            return NULL;

        if (root->val == key)
            return helper(root);

        TreeNode* curr = root;

        while (curr)
        {
            if (curr->val < key)
            {
                if (curr->right && curr->right->val == key)
                    curr->right = helper(curr->right);

                else
                    curr = curr->right;
            }

            else if (curr->val > key)
            {
                if (curr->left && curr->left->val == key)
                    curr->left = helper(curr->left);

                else
                    curr = curr->left;
            }
        }
        
        return root;
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

    TreeNode* findLastLeftChild (TreeNode* node)
    {
        while (node && node->left)
            node = node->left;

        return node;
    }

    TreeNode* helper (TreeNode* node)
    {
        if (node->left == NULL)
            return node->right;

        if (node->right == NULL)
            return node->left;

        TreeNode* leftChild = node->left;
        TreeNode* lastLeftChild = findLastLeftChild (node->right);
        lastLeftChild->left = leftChild;
        return node->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == NULL)
            return NULL;

        if (root->val == key)
            return helper(root);

        TreeNode* curr = root;

        while (curr)
        {
            if (curr->val < key)
            {
                if (curr->right && curr->right->val == key)
                    curr->right = helper(curr->right);

                else
                    curr = curr->right;
            }

            else if (curr->val > key)
            {
                if (curr->left && curr->left->val == key)
                    curr->left = helper(curr->left);

                else
                    curr = curr->left;
            }
        }
        
        return root;
    }
};