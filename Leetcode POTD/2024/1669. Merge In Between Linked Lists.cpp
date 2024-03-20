// Problem Link :- https://leetcode.com/problems/merge-in-between-linked-lists/

// Solved by Two Pointer Approach
// Time Complexity :- O(n + m)
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* curr = list1; 

        for (int step = 1; step < a; step++)
            curr = curr->next;

        ListNode* temp = curr->next;
        curr->next = list2;

        for (int step = a; step < b; step++)
            temp = temp->next;

        ListNode* list2Tail = NULL, *curr2 = list2;

        while (curr2)
        {
            list2Tail = curr2;
            curr2 = curr2->next;
        }

        list2Tail->next = temp->next;
        temp->next = NULL;

        return list1;
    }
};



class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* start = NULL, *end = list1;

        for (int index = 1; index <= b; index++) 
        {
            if (index == a)
                start = end;

            end = end->next;
        }

        start->next = list2;

        ListNode* tail = list2;
        
        while (tail->next)
            tail = tail->next;
        
        tail->next = end->next;
        end->next =  NULL;

        return list1;
    }
};