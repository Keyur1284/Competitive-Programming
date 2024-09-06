// Problem Link :- https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

// Solved using unordered_set
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> numSet(nums.begin(), nums.end());

        while(head && numSet.count(head->val))
            head = head->next;

        ListNode* prev = NULL, *curr = head;

        while (curr)
        {
            if (numSet.count(curr->val))
            {
                curr = curr->next;
                continue;
            }

            if (prev)
                prev->next = curr;
            
            prev = curr;
            curr = curr->next;
        }

        if (prev)
            prev->next = NULL;

        return head;
    }
};



class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> vis(nums.begin(), nums.end());
        ListNode* newHead = NULL, *prev = NULL;

        while(head)
        {
            if (vis.count(head->val))
            {
                head = head->next;
                continue;
            }

            if (newHead)
            {
                prev->next = head;
                prev = head;
            }

            else
            {
                prev = newHead = head;
            }

            head = head->next;
        }

        if (prev)
            prev->next = NULL;

        return newHead;
    }
};



class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        while (head && valuesToRemove.count(head->val)) 
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == NULL)
            return NULL;

        ListNode* current = head;
        
        while (current->next) 
        {
            if (valuesToRemove.contains(current->next->val)) 
            {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } 
            
            else
                current = current->next;
        }

        return head;
    }
};