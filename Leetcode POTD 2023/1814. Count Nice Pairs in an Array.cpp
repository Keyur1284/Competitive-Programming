// Problem Link :- https://leetcode.com/problems/count-nice-pairs-in-an-array/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int MOD = 1e9 + 7;

    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int, int> freq;

        for (auto &it : nums)
        {
            int val = it;
            string rev = "";

            while (val > 0)
            {
                int digit = val % 10;
                val /= 10;
                rev += digit + '0';
            }

            int revNum = (rev.length()) ? stoi(rev) : 0;
            freq[it - revNum]++;
        }

        long count = 0;

        for (auto &it : freq)
        {
            count += 1LL * (it.second) * (it.second - 1) >> 1;
            count %= MOD;
        }

        return count;
    }
};



class Solution {
public:

    int MOD = 1e9 + 7;

    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int, int> freq;

        for (auto &it : nums)
        {
            int val = it;
            int rev = 0;

            while (val > 0)
            {
                int digit = val % 10;
                val /= 10;
                rev = rev * 10 + digit;
            }

            freq[it - rev]++;
        }

        long count = 0;

        for (auto &it : freq)
        {
            count += 1LL * (it.second) * (it.second - 1) >> 1;
            count %= MOD;
        }

        return count;
    }
};