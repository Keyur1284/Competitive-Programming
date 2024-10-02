// Problem Link :- https://leetcode.com/problems/rank-transform-of-an-array/

// Solved by Sorting and using Map
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();
        map<int, int> numToRank;
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());

        for (int i = 0, rank = 1; i < n; i++) 
        {
            if (i > 0 && sortedArr[i] > sortedArr[i - 1])
                rank++;
            
            numToRank[sortedArr[i]] = rank;
        }

        for (int i = 0; i < n; i++) 
        {
            arr[i] = numToRank[arr[i]];
        }
        
        return arr;
    }
};



// Solved using Set and Map
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int, int> numToRank;

        set<int> nums(arr.begin(), arr.end());

        int rank = 1;
        
        for (auto num : nums) 
        {
            numToRank[num] = rank;
            rank++;
        }
        
        for (int i = 0; i < n; i++) 
        {
            arr[i] = numToRank[arr[i]];
        }

        return arr;
    }
};



// Solved using Map
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        map<int, vector<int>> numToIndices;

        for (int i = 0; i < n; i++) 
        {
            numToIndices[arr[i]].emplace_back(i);
        }

        int rank = 1;

        for (auto& pair : numToIndices) 
        {
            for (int index : pair.second) 
            {
                arr[index] = rank;
            }
            
            rank++;
        }
        
        return arr;
    }
};