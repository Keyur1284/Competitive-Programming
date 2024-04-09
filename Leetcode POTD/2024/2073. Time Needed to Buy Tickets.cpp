// Problem Link :- https://leetcode.com/problems/time-needed-to-buy-tickets/

// Solved by Simulation using Queue
// Time Complexity :- O(n * k)
// Space Complexity :- O(n)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int n = tickets.size(), time = 0;
        queue<int> q;

        for (int i = 0; i < n; i++)    
            q.emplace(i);

        while (!q.empty())
        {
            int index = q.front();
            q.pop();
            time++;

            tickets[index]--;

            if (tickets[index] == 0 && index == k)
                return time;

            if (tickets[index])
                q.emplace(index);
        }

        return -1;
    }
};


// Solved by Simulation without using Queue
// Time Complexity :- O(n * k)
// Space Complexity :- O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int time = 0;

        while (1)
        {
            for (auto &it : tickets)
            {
                if (it)
                {
                    it--;
                    time++;
                }

                if (tickets[k] == 0)
                    return time;
            }
        }

        return -1;
    }
};



// Solved in One Pass
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int time = 0, n = tickets.size();

        for (int i = 0; i < n; i++)
        {
            time += (i <= k) ? min(tickets[i], tickets[k]) : min(tickets[i], tickets[k] - 1);
        }

        return time;
    }
};