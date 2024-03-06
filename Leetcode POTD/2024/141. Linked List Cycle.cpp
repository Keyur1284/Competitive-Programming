// Problem Link :- https://leetcode.com/problems/linked-list-cycle/

// Solved by using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> vis;

        while (head)
        {
            if (vis.find(head) != vis.end())
                return true;
            
            vis.emplace(head);
            head = head->next;
        }

        return false;
    }
};



// Solved by using Floyd's Tortoise and Hare (Cycle Detection) Algorithm
// Time Complexity :- O(n)
// Space Complexity :- O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* hare = head, *tortoise = head;

        while (hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;

            if (hare == tortoise)
                return true;
        }

        return false;
    }
};