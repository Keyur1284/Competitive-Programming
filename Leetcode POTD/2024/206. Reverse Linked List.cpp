// Problem Link :- https://leetcode.com/problems/reverse-linked-list/

// Solved by Iterative Approach
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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* newHead = NULL;

        while (head)
        {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }

        return newHead;
    }
};



// Solved by Recursive Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};
