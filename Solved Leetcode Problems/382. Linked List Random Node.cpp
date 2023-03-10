// Problem Link :- https://leetcode.com/problems/linked-list-random-node/

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

    vector<int> vec;

    Solution(ListNode* head) {

        while(head)
        {
            vec.emplace_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        
        int size = vec.size();
        int ans = vec[rand() % size];

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */


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

    ListNode* first;

    Solution(ListNode* head) {
        
        first = head;
    }
    
    int getRandom() {

        ListNode* curr = first;
        int ans = curr->val;
        int index = 1;

        while(curr)
        {
            if(rand() % index == 0)
                ans = curr->val;

            curr = curr->next;
            index++;
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */