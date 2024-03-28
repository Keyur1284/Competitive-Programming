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



// Solved by filling the idle slots
// Time Complexity :- O(n + 26 * log(26))
// Space Complexity :- O(26)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for (auto &ch : tasks) 
            freq[ch - 'A']++;

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25] - 1;
        int idleSlots = maxFreq * n;

        for (int i = 24; i >= 0 && freq[i] > 0; i--) 
        {
            idleSlots -= min(maxFreq, freq[i]);
        }

        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};



// Solved by Greedy Approach
// Time Complexity :- O(n)
// Space Complexity :- O(26)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);
        int maximum = 0, maxCount = 0;

        for (auto &ch : tasks) 
        {
            freq[ch - 'A']++;
            
            if (freq[ch - 'A'] > maximum) 
            {
                maximum = freq[ch - 'A'];
                maxCount = 1;
            } 

            else if (freq[ch - 'A'] == maximum) 
                maxCount++;
        }
        
        int partCount = maximum - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maximum * maxCount;
        int idles = max(0, emptySlots - availableTasks);
        
        return tasks.size() + idles;
    }
};



// Solved by Math
// Time Complexity :- O(n)
// Space Complexity :- O(26)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);
        int maximum = 0, maxCount = 0;

        for (auto &ch : tasks) 
        {
            freq[ch - 'A']++;
            
            if (freq[ch - 'A'] > maximum) 
            {
                maximum = freq[ch - 'A'];
                maxCount = 1;
            } 

            else if (freq[ch - 'A'] == maximum) 
                maxCount++;
        }
        
        int time = (maximum - 1) * (n + 1) + maxCount;
        
        return max((int)tasks.size(), time);
    }
};