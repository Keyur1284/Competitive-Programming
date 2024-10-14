// Problem Link :- https://leetcode.com/problems/maximal-score-after-applying-k-operations/

// Solved using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        long long ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());

        while (k--) 
        {
            int maxElement = pq.top();
            pq.pop();
            ans += maxElement;
            pq.push(ceil(maxElement / 3.0));
        }
        
        return ans;
    }
};