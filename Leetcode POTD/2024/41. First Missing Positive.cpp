// Problem Link :- https://leetcode.com/problems/first-missing-positive/

// Solved using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_set<int> st;

        for (auto &it : nums)
        {
            if (it > 0)
                st.emplace(it);
        }

        int mex = 1;

        while (st.count(mex))
            mex++;

        return mex;
    }
};



// Solved using boolean vector
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> vis(n + 1, false); 

        for (auto &it : nums) 
        {
            if (it > 0 && it <= n) 
                vis[it] = true;
        }

        for (int i = 1; i <= n; i++) 
        {
            if (!vis[i])
                return i;
        }

        return n + 1;
    }
};



// Solved by modifying the input array
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
        int n = nums.size();
        bool contains1 = false;

        for (int i = 0; i < n; i++) 
        {
            if (nums[i] == 1) 
                contains1 = true;
            
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }

        if (!contains1) 
            return 1;

        for (int i = 0; i < n; i++) 
        {
            int value = abs(nums[i]);
            
            // if (value == n) 
            //     nums[0] = - abs(nums[0]);
            
            // else
            //     nums[value] = - abs(nums[value]);
            
            nums[value % n] = -abs(nums[value % n]);
        }

        for (int i = 1; i < n; i++) 
        {
            if (nums[i] > 0)
                return i;
        }

        if (nums[0] > 0) 
            return n;

        return n + 1;
    }
};



// Solved by Cyclic Sort
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};