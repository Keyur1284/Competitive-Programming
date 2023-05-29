// Problem Link :- https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723

// Brute Force Code
// Time Complexity :- O(N^2)
// Space Complexity :- O(H)     H = height of binary tree;

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void increment(BinaryTreeNode<int>* root, int diff)
{
    if (root->left)
    {
        root->left->data += diff;
        
        increment (root->left, diff);
    }

    else if (root->right)
    {
        root->right->data += diff;
        
        increment (root->right, diff);
    }
}

void changeTree(BinaryTreeNode<int>* root) {
    
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    int left = 0, right = 0, curr = root->data;

    changeTree (root->left);
    changeTree (root->right);

    if (root->left)
        left = root->left->data;

    if (root->right)
        right = root->right->data;

    int diff = left + right - curr;

    if (diff >= 0)
        root->data += diff;

    else if (diff < 0)
        increment(root, -diff);
}  



// Optimized Code
// Time Complexity :- O(N)
// Space Complexity :- O(H)     H = height of binary tree;

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    
    if (root == NULL)
        return;

    int left = 0, right = 0, curr = root->data;
    
    if (root->left)
        left = root->left->data;

    if (root->right)
        right = root->right->data;

    int diff = left + right - curr;

    if (diff >= 0)
        root->data += diff;

    else
    {
        if (root->left)
            root->left->data = curr;

        if (root->right)
            root->right->data = curr;
    }

    changeTree (root->left);
    changeTree (root->right);
    
    int newLeft = 0, newRight = 0;

    if (root->left)
        newLeft = root->left->data;

    if (root->right)
        newRight = root->right->data;
    
    if (root->left || root->right)
        root->data = newLeft + newRight;
}  