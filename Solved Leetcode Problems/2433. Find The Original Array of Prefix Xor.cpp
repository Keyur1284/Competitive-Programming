// Problem Link :- https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

// Solved by traversing left to right
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        int n = pref.size();
        vector<int> nums;
        nums.emplace_back(pref[0]);

        for (int i = 1; i < n; i++)
        {
            nums.emplace_back(pref[i] ^ pref[i - 1]);
        }

        return nums;
    }
};



// Solved by traversing right to left
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        int n = pref.size();
        
        for (int i = n - 1; i > 0; i--) 
        {
            pref[i] ^= pref[i - 1];
        }
        
        return pref;
    }
};