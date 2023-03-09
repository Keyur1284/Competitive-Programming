// Problem Link :- https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set <ListNode*> st;
        ListNode *curr = head;

        while (curr)
        {
            if (st.find(curr) != st.end())
                return curr;

            st.emplace(curr);
            curr = curr->next;
        }

        return NULL;
    }
};


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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *tortoise = head;
        ListNode *hare = head;

        while (hare != NULL && hare->next != NULL)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;

            if (hare == tortoise)
            {
                tortoise = head;

                while (tortoise != hare)
                {
                    hare = hare->next;
                    tortoise = tortoise->next;
                }

                return tortoise;
            }
        }

        return NULL;
    }
};