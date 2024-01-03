// Problem Link :- https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/

// Solved by counting left zeros and right ones
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxScore(string s) {
        
        int n = s.length();
        int one = count(s.begin(), s.end(), '1');
        int zero = 0, maxscore = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
                zero++;
            else
                one--;

            int score = zero + one;
            maxscore = max(maxscore, score);
        }

        return maxscore;
    }
};



// Solved in one pass
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxScore(string s) {
        
        int n = s.length();
        int one = 0, zero = 0, maxscore = INT_MIN;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '1')
                one++;
            else
                zero++;

            int score = zero - one;
            maxscore = max(maxscore, score);
        }

        if (s[n - 1] == '1')
            one++;

        return maxscore + one;
    }
};