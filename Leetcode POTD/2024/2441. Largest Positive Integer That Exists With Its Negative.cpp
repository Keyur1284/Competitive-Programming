// Problem Link :- https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

// Solved by Brute Force Approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        int ans = -1;

        for (auto &it : nums)
        {
            if (it < 0)
                continue;

            for (auto &it2 : nums)
            {
                if (it2 == -it)
                {
                    ans = max(ans, it);
                    break;
                }
            }
        }

        return ans;
    }
};



// Solved by Sorting + Two Pointer Approach
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), left = 0, right = n - 1, ans = -1;

        while (left < right)
        {
            if (-nums[left] == nums[right])
            {
                ans = nums[right];
                break;
            }

            (-nums[left] > nums[right]) ? left++ : right--;
        }
        
        return ans;
    }
};



// Solved using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        unordered_set<int> pos;
        
        int ans = -1;

        for (auto &it : nums)
        {
            if (it > 0)
                pos.emplace(-it);
        }

        for (auto &it : nums)
        {
            if (it < 0 && pos.count(it))
                ans = max(ans, -it);
        }

        return ans;
    }
};



class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        unordered_set<int> vis;
        
        int ans = -1;

        for (auto &it : nums)
        {
            int absVal = abs(it);

            if (absVal > ans && vis.count(-it))
                ans = absVal;

            vis.emplace(it);
        }

        return ans;
    }
};



// Solved using bitset
// Time Complexity :- O(n)
// Space Complexity :- O(2001)

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        bitset<2001> vis;
        
        int ans = -1;

        for (auto &it : nums)
        {
            int absVal = abs(it);

            // if (absVal > ans && vis.test(-it + 1000))
            if (absVal > ans && vis[-it + 1000])
                ans = absVal;


            vis[it + 1000] = 1;
            // vis.set(it + 1000);
        }

        return ans;
    }
};



// Solved using boolean vector
// Time Complexity :- O(n)
// Space Complexity :- O(2001)

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        vector<bool> vis(2001, false);
        
        int ans = -1;

        for (auto &it : nums)
        {
            int absVal = abs(it);

            if (absVal > ans && vis[-it + 1000])
                ans = absVal;

            vis[it + 1000] = true;
        }

        return ans;
    }
};