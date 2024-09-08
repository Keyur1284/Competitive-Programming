// Problem Link :- https://leetcode.com/problems/linked-list-in-binary-tree/

// Solved by Recursive Approach
// Time Complexity :- O(n * m)
// Space Complexity :- O(n + m)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {

        if (root == NULL) 
            return false;

        return isSubPath(head, root->left) || isSubPath(head, root->right) || checkSubPath(root, head);
    }
    
    bool checkSubPath(TreeNode* root, ListNode* curr) {
        
        if (curr == NULL) 
            return true;
        
        if (root == NULL || root->val != curr->val) 
            return false;
        
        return checkSubPath(root->left, curr->next) || checkSubPath(root->right, curr->next);
    }
};



// Solved by KMP Algorithm
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {

        vector<int> pattern = {head->val}, prefixTable = {0};
        int patternIndex = 0;
        head = head->next;

        while (head) 
        {
            while (patternIndex && head->val != pattern[patternIndex])
                patternIndex = prefixTable[patternIndex - 1];
            
            patternIndex += head->val == pattern[patternIndex];
            pattern.emplace_back(head->val);
            prefixTable.emplace_back(patternIndex);
            head = head->next;
        }

        return searchInTree(root, 0, pattern, prefixTable);
    }

private:
    bool searchInTree(TreeNode* node, int patternIndex, const vector<int>& pattern, const vector<int>& prefixTable) {
        
        if (node == NULL) 
            return false;

        while (patternIndex && node->val != pattern[patternIndex])
            patternIndex = prefixTable[patternIndex - 1];
        
        patternIndex += node->val == pattern[patternIndex];

        if (patternIndex == pattern.size()) 
            return true;

        return searchInTree(node->left, patternIndex, pattern, prefixTable) || searchInTree(node->right, patternIndex, pattern, prefixTable);
    }
};