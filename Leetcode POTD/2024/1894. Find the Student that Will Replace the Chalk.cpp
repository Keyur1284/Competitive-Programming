// Problem Link :- https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

// Solved by Math
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int n = chalk.size();
        long long chalkSum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= chalkSum;

        for (int i = 0; i < n; i++)
        {
            if (k < chalk[i])
                return i;

            k -= chalk[i];
        }

        return -1;
    }
};



// Solved by Prefix Sum + Binary Search
// Time Complexity :- O(n + logn)
// Space Complexity :- O(n)

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int n = chalk.size();
        
        vector<long long> prefixSum(n);
        prefixSum[0] = chalk[0];
        
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + chalk[i];

        k %= prefixSum[n - 1];
        
        return lower_bound(prefixSum.begin(), prefixSum.end(), k + 1) - prefixSum.begin();
        // return upper_bound(prefixSum.begin(), prefixSum.end(), k) - prefixSum.begin();
    }
};