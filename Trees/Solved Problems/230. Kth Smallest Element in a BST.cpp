// Problem Link :- https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Solved by Inorder Traversal
// Time Complexity :- O(N)
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

    int ans;

    void Inorder (TreeNode* node, int &k)
    {
        if (node == NULL)
            return;

        Inorder (node->left, k);
        k--;

        if (k == 0)
        {
            ans = node->val;
            return;
        }

        Inorder (node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        Inorder (root, k);
        return ans;
    }
};


// Code for Kth Largest Element in BST

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

    int ans;

    void Inorder (TreeNode* node, int &k)
    {
        if (node == NULL)
            return;

        Inorder (node->right, k);
        k--;

        if (k == 0)
        {
            ans = node->val;
            return;
        }

        Inorder (node->left, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        Inorder (root, k);
        return ans;
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

    int ans;

    TreeNode* Inorder (TreeNode* node, int &k)
    {
        if (node == NULL)
            return NULL;

        TreeNode* left = Inorder (node->left, k);

        if (left)
            return left;

        k--;

        if (k == 0)
            return node;

        return Inorder (node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        TreeNode* node = Inorder (root, k);
        
        return (node) ? node->val : -1; 
    }
};



// Code for Kth Largest Element in BST

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

    int ans;

    TreeNode* Inorder (TreeNode* node, int &k)
    {
        if (node == NULL)
            return NULL;

        TreeNode* right = Inorder (node->right, k);

        if (right)
            return right;

        k--;

        if (k == 0)
            return node;

        return Inorder (node->left, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        TreeNode* node = Inorder (root, k);
        
        return (node) ? node->val : -1; 
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

    int Inorder (TreeNode* node, int &k)
    {
        if (node == NULL)
            return -1;

        int left = Inorder (node->left, k);

        if (left != -1)
            return left;

        k--;

        if (k == 0)
            return node->val;

        return Inorder (node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        int nodeVal = Inorder (root, k);
    
        return nodeVal; 
    }
};


// Code for Kth Largest Element in BST


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

    int Inorder (TreeNode* node, int &k)
    {
        if (node == NULL)
            return -1;

        int right = Inorder (node->right, k);

        if (right != -1)
            return right;

        k--;

        if (k == 0)
            return node->val;

        return Inorder (node->left, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        int nodeVal = Inorder (root, k);
    
        return nodeVal; 
    }
};



// Solved by Morris Inorder Traversal Algorithm (Most Optimized Solution)
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
    int kthSmallest(TreeNode* root, int k) {

        int ans = -1;
        TreeNode* curr = root;

        while (curr)
        {
            if (curr->left == NULL)
            {
                k--;

                if (k == 0)
                    ans = curr->val;

                curr = curr->right;
            }

            else
            {
                TreeNode* prev = curr->left;

                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }

                else if (prev->right == curr)
                {
                    prev->right = NULL;

                    k--;

                    if (k == 0)
                        ans = curr->val;

                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};



// Code for Kth Largest Element in BST

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
    int kthSmallest(TreeNode* root, int k) {

        int ans = -1;
        TreeNode* curr = root;

        while (curr)
        {
            if (curr->right == NULL)
            {
                k--;

                if (k == 0)
                    ans = curr->val;

                curr = curr->left;
            }

            else
            {
                TreeNode* prev = curr->right;

                while (prev->left && prev->left != curr)
                    prev = prev->left;

                if (prev->left == NULL)
                {
                    prev->left = curr;
                    curr = curr->right;
                }

                else if (prev->left == curr)
                {
                    prev->left = NULL;

                    k--;

                    if (k == 0)
                        ans = curr->val;

                    curr = curr->left;
                }
            }
        }

        return ans;
    }
};