// Problem Link :- https://leetcode.com/problems/count-elements-with-maximum-frequency/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> freq;

        for (auto &it : nums)
            freq[it]++;

        int maxi = 0;

        for (auto &it : freq)
            maxi = max(maxi, it.second);

        int count = 0;

        for (auto &it : freq)
            count += (it.second == maxi) ? maxi : 0;

        return count;
    }
};



// Solved using unordered_map (in one pass)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        int maxFreq = 0, totalFreq = 0;

        for (auto &it : nums)
        {
            freq[it]++;

            if (freq[it] > maxFreq)
            {
                maxFreq = freq[it];
                totalFreq = maxFreq;
            }

            else if (freq[it] == maxFreq)
                totalFreq += maxFreq;
        }

        return totalFreq;
    }
};