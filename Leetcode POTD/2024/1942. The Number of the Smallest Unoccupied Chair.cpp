// Problem Link :- https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

// Solved using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        vector<pair<int, int>> events;

        for (int i = 0; i < n; i++) 
        {
            events.emplace_back(times[i][0], i);
            events.emplace_back(times[i][1], ~i);
        }

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

        for (int i = 0; i < n; i++)
            availableChairs.emplace(i);

        for (auto& event : events) 
        {
            auto [time, friendIndex] = event;

            while (!occupiedChairs.empty() && occupiedChairs.top().first <= time) 
            {
                availableChairs.emplace(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            if (friendIndex >= 0) 
            {
                int chair = availableChairs.top();
                availableChairs.pop();
            
                if (friendIndex == targetFriend) 
                    return chair;
                
                occupiedChairs.emplace(times[friendIndex][1], chair);
            }
        }

        return -1;
    }
};



// Solved using set
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;
        int targetArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        int nextChair = 0;
        set<int> availableChairs;

        for (auto time : times) 
        {
            int arrival = time[0], leave = time[1];

            while (!leavingQueue.empty() && leavingQueue.top().first <= arrival) 
            {
                availableChairs.emplace(leavingQueue.top().second);
                leavingQueue.pop();
            }

            int currentChair;

            if (!availableChairs.empty()) 
            {
                currentChair = *availableChairs.begin();
                availableChairs.erase(availableChairs.begin());
            } 
            
            else
                currentChair = nextChair++;

            leavingQueue.emplace(leave, currentChair);

            if (arrival == targetArrival) 
                return currentChair;
        }

        return 0;
    }
};