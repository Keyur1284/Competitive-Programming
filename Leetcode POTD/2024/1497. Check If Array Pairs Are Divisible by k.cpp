// Problem Link :- https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

// Solved by Maths
// Time Complexity :- O(n)
// Space Complexity :- O(k)

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        vector<int> remFreq(k + 1, 0);

        for (auto &it : arr)
            remFreq[(it % k + k) % k]++;

        for (int i = 1; i < k/2 + 1; i++)
        {
            if (remFreq[i] != remFreq[k - i])
                return false;
        }

        return !(remFreq[0] & 1);
    }
};