// Problem Link :- https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// Solved by Brute Force Approach
// Time Complexity :- O(n^2)
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* front = new ListNode(0, head), *start = front;

        while (start) 
        {    
            int prefixSum = 0;
            ListNode* end = start->next;

            while (end) 
            {
                prefixSum += end->val;

                if (prefixSum == 0) 
                    start->next = end->next;

                end = end->next;
            }

            start = start->next;
        }

        return front->next;
    }
};



// Solved using unordered_map (Two Pass)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* front = new ListNode(0, head), *start = front;
        unordered_map<int, ListNode*> map;
        int prefixSum = 0;
        
        while (start) 
        {    
            prefixSum += start->val;
            map[prefixSum] = start;
            start = start->next;
        }
        
        prefixSum = 0;
        start = front;
        
        while (start) 
        {
            prefixSum += start->val;
            start->next = map[prefixSum]->next;
            start = start->next;
        }

        return front->next;
    }
};



// Solved using unordered_map (One Pass)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* front = new ListNode(0, head), *start = front;
        unordered_map<int, ListNode*> map;
        int prefixSum = 0;

        while (start) 
        {
            prefixSum += start->val;

            if (map.count(prefixSum)) 
            {
                ListNode* prev = map[prefixSum];
                start = prev->next;

                int tempSum = prefixSum + start->val;
                
                while (tempSum != prefixSum) 
                {
                    map.erase(tempSum);
                    start = start->next;
                    tempSum += start->val;
                }

                prev->next = start->next;
            } 
            
            else 
                map[prefixSum] = start;

            start = start->next;
        }

        return front->next;
    }
};