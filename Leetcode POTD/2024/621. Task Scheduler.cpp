// Problem Link :- https://leetcode.com/problems/task-scheduler/

// Solved using priority queue
// Time Complexity :- O(n * log(26))
// Space Complexity :- O(26)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for (auto &ch : tasks) 
            freq[ch - 'A']++;

        priority_queue<int> pq;

        for (int i = 0; i < 26; i++) 
        {
            if (freq[i] > 0) 
                pq.emplace(freq[i]);
        }

        int time = 0;

        while (!pq.empty()) 
        {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;

            while (cycle-- && !pq.empty()) 
            {
                if (pq.top() > 1) 
                    store.emplace_back(pq.top() - 1);
                
                pq.pop();
                taskCount++;
            }

            for (auto &it : store) {
                pq.emplace(it);
            }

            time += (pq.empty() ? taskCount : n + 1);
        }
        
        return time;
    }
};