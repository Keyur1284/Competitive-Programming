// Problem Link :- https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

// Solved using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        priority_queue<pair<int, int>> pq;

        for (auto &it : arr)
        {
            int ones = __builtin_popcount(it);
            pq.emplace(ones, it);
        }

        vector<int> ans;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            ans.emplace_back(it.second);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};



// Solved using custom comparator
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    
    static bool comp(const int &a, const int &b) 
    {
        
        if (__builtin_popcount(a) == __builtin_popcount(b))
            return a < b;
        
        return __builtin_popcount(a) < __builtin_popcount(b);
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};



// Solved by Bit Manipulation
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
   
    static int findWeight (int num) 
    {
        int mask = 1;
        int weight = 0;
        
        while (num > 0) 
        {
            if ((num & mask) > 0) 
            {
                weight++;
                num ^= mask;
            }
            
            mask <<= 1;
        }
        
        return weight;
    }
    
    static bool comp (int a, int b)
    {
        if (findWeight(a) == findWeight(b)) 
            return a < b;
        
        return findWeight(a) < findWeight(b);
    }
    
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};



// Solved by Brian Kerninghan's Algorithm
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
   
    static int findWeight (int num) 
    {
        int weight = 0;
        
        while (num > 0) 
        {
            weight++;
            num &= (num - 1);
        }
        
        return weight;
    }
    
    static bool comp (int a, int b)
    {
        if (findWeight(a) == findWeight(b)) 
            return a < b;
        
        return findWeight(a) < findWeight(b);
    }
    
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};