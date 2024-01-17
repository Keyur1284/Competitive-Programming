// Problem Link :- https://leetcode.com/problems/unique-number-of-occurrences/

// Solved using unordered_map and unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        unordered_set<int> st;

        for (auto &it : arr) 
            mp[it]++;
        
        for (auto &it : mp)
        {
            if (st.count(it.second))
                return false;
            
            st.emplace(it.second);
        }
        
        return true;
    }
};



// Solved using frequency array
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<int> freq(2001, 0);

        for (auto &it : arr)
            freq[it + 1000]++;

        unordered_set<int> st;

        for (auto &it : freq)
        {
            if (it)
            {
                if (st.count(it))
                    return false;
                
                st.emplace(it);
            }
        }

        return true;
    }
};