// Problem Link :- https://leetcode.com/problems/optimal-partition-of-string/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by using unordered_map

class Solution {
public:
    int partitionString(string s) {
        
        unordered_map <char, int> mp;
        int ans = 1;

        for (auto &it : s)
        {
            if (mp.find(it) != mp.end())
            {
                ans++;
                mp.clear();
            }
            
            mp[it]++;
        }

        return ans;
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(1);

// Solved by bit manipulation

class Solution {
public:
    int partitionString(string s) {
        
        int ans = 1, flag = 0;

        for (auto &it : s)
        {
            int index = it - 'a';
            int bit = 1 << index;

            if (flag & bit)
            {
                ans++;
                flag = 0;
            }

            flag |= bit;
        }

        return ans;
    }
};