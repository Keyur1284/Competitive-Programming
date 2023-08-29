// Problem Link :- https://leetcode.com/problems/minimum-penalty-for-a-shop/

// Solved by PrefixN Sum and SuffixY Sum
// Time Complexity :- O(N)
// Space Complexity :- O(N)

class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.length();
        vector<int> prefN(n + 1, 0), suffY(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefN[i + 1] = prefN[i] + (customers[i] == 'N');
        }

        for (int i = n - 1; i >= 0; i--)
        {
            suffY[i] = suffY[i + 1] + (customers[i] == 'Y');
        }

        int closingHour = -1, minPenalty = n;

        for (int i = 0; i <= n; i++)
        {
            int penalty = prefN[i] + suffY[i];

            if (penalty < minPenalty)
            {
                minPenalty = penalty;
                closingHour = i;
            }
        }

        return closingHour;
    }
};



// Solved by PrefixN Sum and SuffixY Sum with Space Complexity O(1)
// Time Complexity :- O(N)
// Space Complexity :- O(1)

class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.length();
        int prefN = 0, suffY = 0;

        for (auto &it : customers)
            suffY += (it == 'Y');

        int closingHour = -1, minPenalty = n;

        for (int i = 0; i <= n; i++)
        {
            int penalty = prefN + suffY;

            if (penalty < minPenalty)
            {
                minPenalty = penalty;
                closingHour = i;
            }

            prefN += (customers[i] == 'N');
            suffY -= (customers[i] == 'Y');
        }

        return closingHour;
    }
};



class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.length();
        int score = 0, maxScore = 0, closingHour = -1;

        for (int i = 0; i < n; i++)
        {
            score += (customers[i] == 'Y') ? 1 : -1;

            if (score > maxScore)
            {
                maxScore = score;
                closingHour = i;
            }
        }

        return closingHour + 1;
    }
};