// Problem Link :- https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

// Solved by Math + Game Theory
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.size();
        int alice = 0, bob = 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
            {
                (colors[i] == 'A') ? alice++ : bob++;
            }
        }

        return (alice > bob);
    }
};



class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.length();
        int alice = 0, bob = 0;
        char prev = 'C';

        for (int i = 0; i < n; i++)
        {
            if (colors[i] == prev)
            {
                int len = 1;

                while (i < n && colors[i] == prev)
                    i++, len++;

                if (len >= 3)
                {
                    prev == 'A' ? alice += len - 2 : bob += len - 2;
                }
            }

            if (i < n)
                prev = colors[i];
        }

        return (alice > bob);
    }
};