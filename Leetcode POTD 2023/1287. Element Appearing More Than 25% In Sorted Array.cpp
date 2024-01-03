// Problem Link :- https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        unordered_map<int, int> freq;

        for (auto &it : arr)
            freq[it]++;

        int target = arr.size() / 4;
        
        for(auto &it : freq)
        {
            if (it.second > target)
                return it.first;
        }

        return -1;
    }
};



class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        unordered_map<int, int> freq;
        int target = arr.size() / 4;

        for (auto &it : arr)
        {
            freq[it]++;

            if (freq[it] > target)
                return it;
        }

        return -1;
    }
};



// Solved without using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size(), target = n / 4;

        for (int i = 0; i < n - target; i++)
        {
            if (arr[i] == arr[i + target])
                return arr[i];
        }

        return -1;
    }
};



// Solved using Binary Search
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size(), target = n / 4;
        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};

        for (auto &it : candidates)
        {
            auto left = lower_bound(arr.begin(), arr.end(), it);
            auto right = upper_bound(arr.begin(), arr.end(), it);
            
            if (right - left > target)
                return it;
        }

        return -1;
    }
};