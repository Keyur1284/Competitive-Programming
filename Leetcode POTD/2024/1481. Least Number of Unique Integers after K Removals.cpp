// Problem Link :- https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

// Solved using unordered_map and sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> freq;

        for (auto &it : arr)
        {
            freq[it]++;
        }

        vector<int> count;

        for (auto &it : freq)
        {
            count.emplace_back(it.second);
        }

        sort(count.begin(), count.end());

        int ans = count.size();

        for (auto &it : count)
        {
            if (k >= it)
            {
                k -= it;
                ans--;
            }

            else
                break;
        }

        return ans;
    }
};



// Solved using unordered_map and min heap
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> freq;

        for (auto &it : arr)
        {
            freq[it]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &it : freq)
        {
            pq.emplace(it.second);
        }

        while (!pq.empty() && k)
        {
            auto it = pq.top();
            pq.pop();

            if (k >= it)
                k -= it;

            else
            {
                pq.emplace(it);
                break;
            }
        }

        return (int)pq.size();
    }
};



// Solved using Counting Sort
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        int n = arr.size();
        unordered_map<int, int> freq;

        for (auto &it : arr)
        {
            freq[it]++;
        }

        vector<int> count(n + 1, 0);

        for (auto &it : freq)
        {
            count[it.second]++;
        }

        int uniqueElements = freq.size();

        for (int i = 1; i <= n; i++)
        {
            int numOfElementsToRemove = min(count[i], k / i);

            k -= numOfElementsToRemove * i;
            uniqueElements -= numOfElementsToRemove;

            if (k <= i)
                break;
        }

        return uniqueElements;
    }
};