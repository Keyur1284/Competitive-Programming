// Problem Link :- https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Solved by traversing
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = 0;
        ListNode* temp = head;
        
        while(temp)
        {
            len++;
            temp = temp->next;
        }

        if(len == n)
            return head->next;
    
        temp = head;

        for(int i = 1; i <= len - n - 1; i++)
            temp = temp->next;

        temp->next = temp->next->next;
        return head;
    }
};



// Solved by using two pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* right = head, *left = head;

        for (int i = 1; i <= n; i++)
            right = right->next;

        if (right == NULL)
            return head->next;

        while (right->next)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return head;
    }
};