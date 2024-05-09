// Problem Link :- https://leetcode.com/problems/maximize-happiness-of-selected-children/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.rbegin(), happiness.rend());
        long long maxHapp = 0;
        int n = happiness.size();
            
        for (int i = 0; i < k; i++)
        {
            maxHapp += max(0, happiness[i] - i);
        }
        
        return maxHapp;
    }
};



// Solved using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        priority_queue<int> pq;
        long long maxHapp = 0;
        int n = happiness.size();
        
        for (int i = 0; i < n; i++)
            pq.emplace(happiness[i]);
        
        for (int i = 0; i < k; i++)
        {
            maxHapp += max(0, pq.top() - i);
            pq.pop();
        }
        
        return maxHapp;
    }
};