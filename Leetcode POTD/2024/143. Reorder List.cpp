// Problem Link :- https://leetcode.com/problems/reorder-list/

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

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
    void reorderList(ListNode* head) {
        
        stack<ListNode*> st;
        ListNode* temp = head;

        while (temp)
        {
            st.emplace(temp);
            temp = temp->next;
        }

        int n = st.size();
        temp = head;

        for (int i = 0; i < n / 2; i++)
        {
            ListNode* next = temp->next;
            temp->next = st.top();
            st.pop();
            temp->next->next = next;
            temp = next;
        }

        if (temp)
            temp->next = NULL;

    }
};