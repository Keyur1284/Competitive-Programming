// Problem Link :- https://leetcode.com/problems/relative-sort-array/

// Solved by Counting Sort
// Time Complexity :- O(n + m + 1000)
// Space Complexity :- O(1000)

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> freq(1001, 0), relativeSorted;
        
        for (auto &it : arr1)
            freq[it]++;

        for (auto &it : arr2)
        {
            while(freq[it]--)
                relativeSorted.emplace_back(it);
        }

        for (int num = 0; num <= 1000; num++)
        {
            while(freq[num]-- > 0)
               relativeSorted.emplace_back(num); 
        }

        return relativeSorted;
    }
};