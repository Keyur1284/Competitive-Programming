// Problem Link :- https://leetcode.com/problems/bag-of-tokens/

// Solved by Sortinf and Two Pointer Approach
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), left = 0, right = n - 1, score = 0, maxScore = 0;

        while (left <= right)
        {
            if (power >= tokens[left])
            {
                power -= tokens[left++];
                score += 1;
                maxScore = max(score, maxScore);
            }

            else if (score >= 1)
            {
                power += tokens[right--];
                score -= 1;
            } 

            else
                break;
        }

        return maxScore;
    }
};