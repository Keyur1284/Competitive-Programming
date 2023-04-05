// Problem Link :- https://leetcode.com/problems/longest-consecutive-sequence/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size(), longest = 1, count = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - 1 == nums[i - 1])
                count++;
                
            else if (nums[i] != nums[i - 1])
                count = 1;

            longest = max(longest, count);
        }

        return min(longest, n);
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty())
            return 0;

        unordered_set <int> st;

        for (auto &it : nums)
            st.emplace(it);
        
        int longest = 1;

        for (auto &it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int num = it;
                int count = 1;

                while (st.find(num + 1) != st.end())
                {
                    num++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};