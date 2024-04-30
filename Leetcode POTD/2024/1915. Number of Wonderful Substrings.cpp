// Problem Link :- https://leetcode.com/problems/number-of-wonderful-substrings/

// Solved by Bitmasking and Prefix XOR
// Time Complexity :- O(n * 10)
// Space Complexity :- O(n)

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        int n = word.length(), mask = 0;
        unordered_map<int, long long> mp;
        mp[mask]++;
        long long answer = 0;

        for (auto &it : word)
        {
            mask ^= (1 << (it - 'a'));
            answer += mp[mask];
            mp[mask]++;

            for (int bit = 0; bit < 10; bit++)
            {
                answer += mp[mask ^ (1 << bit)];
            }
        }
        
        return answer;
    }
};