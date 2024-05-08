// Problem Link :- https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

// Solved by Reversing the linked list
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
    
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = NULL, *curr = head;
        
        while(curr) 
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        
        head = reverseList(head);
        
        ListNode* temp = head;
        int carry = 0;
        
        while(temp) 
        {
            int sum = temp->val * 2 + carry;
            temp->val = sum % 10;
            carry = sum / 10;
            
            if (temp->next == NULL && carry > 0) 
            {
                temp->next = new ListNode(carry);
                break;
            }
            
            temp = temp->next;
        }
        
        return reverseList(head);
    }
};



// Solved by Recursive Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int doubleItUtil(ListNode* head) {
        
        if (head == NULL) 
            return 0;
        
        int carry = doubleItUtil(head->next);
        int sum = head->val * 2 + carry;
        head->val = sum % 10;
        
        return sum / 10;
    }
    
    ListNode* doubleIt(ListNode* head) {

        int carry = doubleItUtil(head);    

        if (carry)
            head = new ListNode(carry, head);

        return head;
    }
};



// Solved using Stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    
    ListNode* doubleIt(ListNode* head) {
        
        stack<int> st;
        ListNode* curr = head;
        
        while (curr)
        {
            st.emplace(curr->val);
            curr = curr->next;
        }
        
        int carry = 0;
        ListNode* newHead = NULL;

        while (!st.empty() || carry) 
        {
            newHead = new ListNode(0, newHead);
            
            int sum = carry;

            if (!st.empty())
            {
                sum += st.top() * 2;
                st.pop();
            }

            newHead->val = sum % 10;
            carry = sum / 10;
        }
        
        return newHead;
    }
};



// Solved by Two Pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    
    ListNode* doubleIt(ListNode* head) {
        
        ListNode* curr = head, *prev = NULL;

        while (curr)
        {
            int twice = 2 * curr->val;

            if (twice < 10)
                curr->val = twice;
            
            else
            {
                curr->val = twice % 10;

                if (prev)
                    prev->val += 1;

                else
                    head = new ListNode(1, curr);
            }

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};



// Solved by Single Pointer
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    
    ListNode* doubleIt(ListNode* head) {
        
        if (head->val >= 5)
            head = new ListNode(0, head);

        ListNode* curr = head;

        while (curr)
        {
            curr->val = (2 * curr->val) % 10;

            if (curr->next && curr->next->val >= 5)
                curr->val += 1;

            curr = curr->next;  
        }

        return head;
    }
};