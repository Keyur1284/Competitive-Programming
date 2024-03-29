// Problem Link :-  https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

// Solved by storing indices of maxElement
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long count = 0;
        int maxElement = *max_element(nums.begin(), nums.end()), n = nums.size();
        vector<int> maxPos;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxElement)
                maxPos.emplace_back(i);

            int freq = maxPos.size();

            if (freq >= k)
                count += maxPos[freq - k] + 1;
        }

        return count;
    }
};



// Solved using Queue
// Time Complexity :- O(n)
// Space Complexity :- O(k)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long count = 0;
        int maxElement = *max_element(nums.begin(), nums.end()), n = nums.size();
        queue<int> maxPos;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxElement)
                maxPos.emplace(i);

            int freq = maxPos.size();

            if (freq < k)
                continue;

            if (freq > k)
                maxPos.pop();

            count += maxPos.front() + 1;
        }

        return count;
    }
};



// Solved by Sliding Window Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long count = 0;
        int maxElement = *max_element(nums.begin(), nums.end()), n = nums.size();
        
        for (int start = 0, end = 0; end < n; end++) 
        {
            if (nums[end] == maxElement)
                k--;
            
            while (!k) 
            {
                if (nums[start++] == maxElement)
                    k++;
            }

            count += start;
        }

        return count;
    }
};