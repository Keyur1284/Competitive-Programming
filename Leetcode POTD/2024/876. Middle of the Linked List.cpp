// Problem Link :- https://leetcode.com/problems/middle-of-the-linked-list/

// Solved by slow and fast pointer approach
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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* hare = head, *tortoise = head;

        while (hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }

        return tortoise;
    }
};