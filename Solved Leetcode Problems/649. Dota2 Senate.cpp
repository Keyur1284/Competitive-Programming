// Problem Link :- https://leetcode.com/problems/dota2-senate/

// Solved by Greedy Approach

// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:

    bool banOpponent (string &senate, char c, int pos)
    {
        bool cycle = false;

        while (1)
        {
            if (pos == 0)
                cycle = true;

            if (senate[pos] == c)
            {
                senate.erase(senate.begin() + pos);
                break;
            }

            pos = (pos + 1) % senate.size();
        }

        return cycle;
    }

    string predictPartyVictory(string senate) {
        
        int n = senate.size();
        int rcount = count(senate.begin(), senate.end(), 'R');
        int dcount = n - rcount;
        int index = 0;

        while (rcount && dcount)
        {
            if (senate[index] == 'R')
            {
                if (banOpponent(senate, 'D', (index + 1) % senate.size()))
                    index--;
                
                dcount--;
            }

            else if (senate[index] == 'D')
            {
                if (banOpponent(senate, 'R', (index + 1) % senate.size()))
                    index--;
                
                rcount--;
            }

            index = (index + 1) % senate.size();
        }

        return rcount == 0 ? "Dire" : "Radiant";
    }
};


// Solved by using a boolean array

// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    void banOpponent (string &senate, char c, int pos, vector<bool> &active)
    {
        while (1)
        {
            if (senate[pos] == c && active[pos])
            {
                active[pos] = false;
                break;
            }

            pos = (pos + 1) % senate.size();
        }
    }

    string predictPartyVictory(string senate) {
        
        int n = senate.size();
        int rcount = count(senate.begin(), senate.end(), 'R');
        int dcount = n - rcount;
        int index = 0;

        vector<bool> active(n, true);

        while (rcount && dcount)
        {
            if (active[index])
            {
                if (senate[index] == 'R')
                {
                    banOpponent(senate, 'D', (index + 1) % senate.size(), active);
                    dcount--;
                }

                else if (senate[index] == 'D')
                {
                    banOpponent(senate, 'R', (index + 1) % senate.size(), active);
                    rcount--;
                }
            }

            index = (index + 1) % senate.size();
        }

        return rcount == 0 ? "Dire" : "Radiant";
    }
};


// Solved by using Binary Search

// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    void banOpponent (int pos, vector<bool> &active, vector<int> &indices)
    {
        auto it = lower_bound(indices.begin(), indices.end(), pos);

        if (it == indices.end())
        {
            active[indices[0]] = false;
            indices.erase(indices.begin());
        }

        else
        {
            active[*it] = false;
            indices.erase(it);
        }
    }

    string predictPartyVictory(string senate) {
        
        int n = senate.size();
        int index = 0;

        vector<bool> active(n, true);
        vector<int> rpos, dpos;

        for (int i = 0; i < n; i++)
        {
            senate[i] == 'R'? rpos.emplace_back(i) : dpos.emplace_back(i);
        }

        while (!rpos.empty() && !dpos.empty())
        {
            if (active[index])
            {
                if (senate[index] == 'R')
                    banOpponent((index + 1) % senate.size(), active, dpos);

                else if (senate[index] == 'D')
                    banOpponent((index + 1) % senate.size(), active, rpos);
            }

            index = (index + 1) % senate.size();
        }

        return rpos.empty() ? "Dire" : "Radiant";
    }
};


// Solved by using 2 Queues

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    string predictPartyVictory(string senate) {
        
        int n = senate.size();
        queue<int> rturns, dturns;

        for (int i = 0; i < n; i++)
        {
            senate[i] == 'R'? rturns.emplace(i) : dturns.emplace(i);
        }

        while (!rturns.empty() && !dturns.empty())
        {
            int r = rturns.front();
            rturns.pop();

            int d = dturns.front();
            dturns.pop();

            if (d > r)
                rturns.emplace(r + n);

            else
                dturns.emplace(d + n);
        }

        return rturns.empty() ? "Dire" : "Radiant";
    }
};


// Solved by using 1 queue

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    string predictPartyVictory(string senate) {
        
        int n = senate.size(), rcount = 0, dcount = 0, band = 0, banr = 0;
        queue<char> q;

        for (auto &it : senate)
        {
            q.emplace(it);
            (it == 'R') ? rcount++ : dcount++;
        }

        while (rcount && dcount)
        {
            char c = q.front();
            q.pop();

            if (c == 'R')
            {
                if (banr)
                {
                    banr--;
                    rcount--;
                }

                else
                {
                    band++;
                    q.emplace('R');
                }
            }

            else if (c == 'D')
            {
                if (band)
                {
                    band--;
                    dcount--;
                }

                else
                {
                    banr++;
                    q.emplace('D');
                }
            }
        }
        
        return rcount ? "Radiant" : "Dire";
    }
};