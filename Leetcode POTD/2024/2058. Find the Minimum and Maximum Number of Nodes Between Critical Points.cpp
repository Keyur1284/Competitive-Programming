// Problem Link :- https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

// Solved by Storing Critical Indices
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

    bool isCriticalPoint(ListNode* prev, ListNode* curr)
    {
        return ((prev->val < curr->val && curr->val > curr->next->val) || (prev->val > curr->val && curr->val < curr->next->val));
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int i = 0;
        ListNode* prev = NULL, *curr = head;
        vector<int> criticalIndices;

        while(curr)
        {
            if (prev && curr->next)
            {
                if (isCriticalPoint(prev, curr))
                    criticalIndices.emplace_back(i);
            }

            i++;
            prev = curr;
            curr = curr->next;
        }

        int n = criticalIndices.size();
        
        if (n < 2)
            return {-1, -1};

        int minDist = INT_MAX, maxDist = criticalIndices.back() - criticalIndices[0];

        for (int i = 1; i < n; i++)
        {
            int dist = criticalIndices[i] - criticalIndices[i - 1];
            minDist = min(dist, minDist);
        }

        return {minDist, maxDist};
    }
};



// Solved in O(1) Space
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    bool isCriticalPoint(ListNode* prev, ListNode* curr)
    {
        return ((prev->val < curr->val && curr->val > curr->next->val) || (prev->val > curr->val && curr->val < curr->next->val));
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> result = {-1, -1};
        int minDistance = INT_MAX;

        ListNode* previousNode = head, * currentNode = head->next;
        int currentIndex = 1, previousCriticalIndex = 0, firstCriticalIndex = 0;

        while (currentNode->next) 
        {
            if (isCriticalPoint(previousNode, currentNode)) 
            {
                if (previousCriticalIndex == 0) 
                {
                    previousCriticalIndex = currentIndex;
                    firstCriticalIndex = currentIndex;
                } 
                
                else 
                {
                    minDistance = min(minDistance, currentIndex - previousCriticalIndex);
                    previousCriticalIndex = currentIndex;
                }
            }

            currentIndex++;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        if (minDistance != INT_MAX) 
        {
            int maxDistance = previousCriticalIndex - firstCriticalIndex;
            result = {minDistance, maxDistance};
        }

        return result;
    }
};