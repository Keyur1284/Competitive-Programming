// Problem Link :- https://leetcode.com/problems/find-players-with-zero-or-one-losses/

// Solved using unordered_map
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int, int> losers;
        
        for (auto &it : matches)
            losers[it[1]]++;
        
        vector<int> notLost, onceLost;
        
        for (auto &it : matches)
        {
            int winner = it[0], loser = it[1];

            if (!losers.count(winner)) 
            {
               notLost.emplace_back(winner);
               losers[winner] = 2;
            }

            if (losers[loser] == 1)
                onceLost.push_back(loser);
        }

        sort(notLost.begin(), notLost.end());    
        sort(onceLost.begin(), onceLost.end());

        return {notLost,onceLost};
    }
};