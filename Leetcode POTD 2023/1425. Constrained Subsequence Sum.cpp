// Problem Link :- https://leetcode.com/problems/constrained-subsequence-sum/

// Solved using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        pq.emplace(nums[0], 0);
        int ans = nums[0];
        
        for (int i = 1; i < n; i++) 
        {
            while (i - pq.top().second > k)
                pq.pop();

            int curr = max(0, pq.top().first) + nums[i];
            ans = max(ans, curr);
            pq.emplace(curr, i);
        }
        
        return ans;
    }
};



// Solved using deque
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int> dq;
        int ans = nums[0];
        
        for (int i = 0; i < n; i++) 
        {
            nums[i] += dq.empty() ? 0 : dq.front();
            ans = max(ans, nums[i]);
            
            while (!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            
            if (nums[i] > 0)
                dq.push_back(nums[i]);
            
            if (i >= k && !dq.empty() && dq.front() == nums[i - k])
                dq.pop_front();
        }
        
        return ans;
    }
};