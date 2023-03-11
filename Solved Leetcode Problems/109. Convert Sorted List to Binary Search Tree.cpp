// Problem Link :- https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

// Time Complexity : O(nlogn)
// Space Complexity : O(n)

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

    vector<int> nodes;

    TreeNode *constructBST(int left, int right)
    {
        if (left > right)
            return NULL;

        int mid = (left + right) >> 1;

        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = constructBST(left, mid - 1);
        root->right = constructBST(mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        if (head == NULL)
            return NULL;

        ListNode* curr = head;
        
        while (curr)
        {
            nodes.emplace_back(curr->val);
            curr = curr->next;
        }

        int size = nodes.size();

        return constructBST(0, size - 1);
    }
};


// Time Complexity : O(nlogn)
// Space Complexity : O(logn)

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

    TreeNode* constructBST(ListNode* left, ListNode* right)
    {
        if (left == right)
            return NULL;

        ListNode *tortoise = left, *hare = left;

        while (hare != right && hare->next != right)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }

        TreeNode* root = new TreeNode(tortoise->val);
        root->left = constructBST(left, tortoise);
        root->right = constructBST(tortoise->next, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        return constructBST(head, NULL);
    }
};