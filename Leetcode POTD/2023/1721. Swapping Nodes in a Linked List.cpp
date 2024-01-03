// Problem Link :- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* tail = head;
        ListNode* front = head;
        int count = 0;

        while (tail)
        {
            tail = tail->next;
            count++;
        }

        tail = head;

        for (int i = 1; i <= k - 1; i++)
            front = front->next;
        
        for (int i = 1; i <= count - k; i++)
            tail = tail->next;

        swap(front->val, tail->val);

        return head;
    }
};


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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* left = head;
        
        for (int i = 1; i <= k - 1; i++)
            left = left->next;

        ListNode* temp = left;
        ListNode* right = head;
        
        while (temp->next)
        {
            right = right->next;
            temp = temp->next;
        }

        swap(left->val, right->val);

        return head;
    }
};