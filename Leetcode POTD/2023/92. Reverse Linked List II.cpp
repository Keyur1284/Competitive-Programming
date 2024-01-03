// Problem Link :- https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* curr = head, *prev = NULL;

        while (left > 1)
        {
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }

        ListNode* midHead = prev, *tail = curr;

        while (right--)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        (midHead) ? (midHead->next = prev) : (head = prev);
        tail->next = curr;
        return head;
    }
};