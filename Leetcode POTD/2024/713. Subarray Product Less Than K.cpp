// Problem Link :- https://leetcode.com/problems/subarray-product-less-than-k/

// Solved using deque
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size(), subarrays = 0;
        long long prod = 1;
        deque<int> dq;
        
        for (int i = 0; i < n; i++)
        {
            prod *= nums[i];
            dq.push_back(nums[i]);
            
            while (!dq.empty() && prod >= k)
            {
                prod /= dq.front();
                dq.pop_front();
            }
            
            subarrays += dq.size();
        }
        
        return subarrays;
    }
};



// Solved by Two Pointer Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size(), subarrays = 0;
        long long prod = 1;

        for (int start = 0, end = 0; end < n; end++)
        {
            prod *= nums[end];

            while (start <= end && prod >= k)
            {
                prod /= nums[start++];
            }

            subarrays += end - start + 1;
        }

        return subarrays;
    }
};