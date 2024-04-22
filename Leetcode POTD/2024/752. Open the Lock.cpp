// Problem Link :- https://leetcode.com/problems/open-the-lock/

// Solved by BFS
// Time Complexity :- O(10^4)
// Space Complexity :- O(10^4)

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> dead(deadends.begin(), deadends.end());
        
        if (dead.count("0000")) 
            return -1;

        queue<string> q;
        q.emplace("0000");
        dead.emplace("0000");
        int moves = 0;

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                string curr = q.front();
                q.pop();

                if (curr == target) 
                    return moves;

                for (int wheel = 0; wheel < 4; wheel++)
                {
                    for (int k = -1; k <= 1; k += 2)
                    {
                        string next = curr;
                        next[wheel] = (next[wheel] - '0' + k + 10) % 10 + '0';

                        if (!dead.count(next))
                        {
                            q.emplace(next);
                            dead.insert(next);
                        }
                    }
                }
            }

            moves++;
        }
        
        return -1;
    }
};