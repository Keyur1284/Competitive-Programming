// Problem Link :- https://leetcode.com/problems/substring-with-largest-variance/

// Solved by modifying Kadane's algorithm
// Time Complexity :- O(26 * 26 * n)
// Space Complexity :- O(1)

class Solution {
public:
    int largestVariance(string s) {
        
        vector<int> freq(26, 0);

        for (auto &it : s)
        {
            int index = it - 'a';
            freq[index]++;
        }

        int maxVar = 0;

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (i == j || freq[i] == 0 || freq[j] == 0)
                    continue;

                char major = i + 'a', minor = j + 'a';
                int majorCount = 0, minorCount = 0, remMinor = freq[j];
                
                for (auto &ch : s)
                {
                    if (ch == major)
                        majorCount++;

                    if (ch == minor)
                    {
                        minorCount++;
                        remMinor--;
                    }

                    int var = majorCount - minorCount;
                    
                    if (minorCount)
                    {
                        maxVar = max(maxVar, var);
                    }

                    if (var < 0 && remMinor)
                    {
                        majorCount = 0;
                        minorCount = 0;
                    }
                }
            }
        }

        return maxVar;
    }
};