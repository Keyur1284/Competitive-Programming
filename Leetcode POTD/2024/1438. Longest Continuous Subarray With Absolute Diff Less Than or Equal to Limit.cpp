// Problem Link :- https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

// Solved using multiset
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size(), maxLen = 0;
        multiset<int> ms;

        for (int start = 0, end = 0; end < n; end++)
        {
            ms.emplace(nums[end]);

            while(!ms.empty() && *ms.rbegin() - *ms.begin() > limit)
            {
                ms.erase(ms.find(nums[start++]));
            }

            int len = end - start + 1;
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};



// Solved using two deques
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size(), maxLen = 0;
        deque<int> minQue, maxQue;

        for (int start = 0, end = 0; end < n; end++)
        {
            while(!maxQue.empty() && nums[maxQue.back()] < nums[end])
                maxQue.pop_back();

            while(!minQue.empty() && nums[minQue.back()] > nums[end])
                minQue.pop_back();

            maxQue.emplace_back(end);
            minQue.emplace_back(end);

            while (nums[maxQue.front()] - nums[minQue.front()] > limit)
            {
                if (nums[maxQue.front()] == nums[start])
                    maxQue.pop_front();

                if (nums[minQue.front()] == nums[start])
                    minQue.pop_front();

                start++;
            }

            int len = end - start + 1;
            maxLen = max(len, maxLen);
        }
        
        return maxLen;
    }
};



class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size(), maxLen = 0;
        deque<int> minQue, maxQue;

        for (int start = 0, end = 0; end < n; end++)
        {
            while(!maxQue.empty() && maxQue.back() < nums[end])
                maxQue.pop_back();

            while(!minQue.empty() && minQue.back() > nums[end])
                minQue.pop_back();

            maxQue.emplace_back(nums[end]);
            minQue.emplace_back(nums[end]);

            while (maxQue.front() - minQue.front() > limit)
            {
                if (maxQue.front() == nums[start])
                    maxQue.pop_front();

                if (minQue.front() == nums[start])
                    minQue.pop_front();

                start++;
            }

            int len = end - start + 1;
            maxLen = max(len, maxLen);
        }
        
        return maxLen;
    }
};