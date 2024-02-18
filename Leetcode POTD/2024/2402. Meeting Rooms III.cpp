// Problem Link :- https://leetcode.com/problems/meeting-rooms-iii/

// Solved by sorting (Brute Force Approach)
// Time Complexity :- O(mlogm + m * n)
// Space Complexity :- O(n + logm)

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        vector<long long> roomAvailabilityTime(n, 0);
        vector<int> meetingCount(n, 0);
        sort(meetings.begin(), meetings.end());

        for (auto &meeting : meetings) 
        {
            int start = meeting[0], end = meeting[1];
            long long minRoomAvailabilityTime = LLONG_MAX;
            int minAvailableTimeRoom = 0;
            bool foundUnusedRoom = false;

            for (int i = 0; i < n; i++) 
            {
                if (roomAvailabilityTime[i] <= start) 
                {
                    foundUnusedRoom = true;
                    meetingCount[i]++;
                    roomAvailabilityTime[i] = end;
                    break;
                }

                if (minRoomAvailabilityTime > roomAvailabilityTime[i]) 
                {
                    minRoomAvailabilityTime = roomAvailabilityTime[i];
                    minAvailableTimeRoom = i;
                }
            }

            if (!foundUnusedRoom) 
            {
                roomAvailabilityTime[minAvailableTimeRoom] += end - start;
                meetingCount[minAvailableTimeRoom]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;

        for (int i = 0; i < n; i++) 
        {
            if (meetingCount[i] > maxMeetingCount) 
            {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        
        return maxMeetingCountRoom;
    }
};

// Solved using priority queue and set
// Time Complexity :- O(m * (logm + logn))
// Space Complexity :- O(n + logm)

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> meets;
        set<int> rooms;
        vector<int> freq(n, 0);

        for (int i = 0; i < n; i++)
            rooms.emplace(i); 

        for (int i = 0; i < m; i++)
        {
            while (!meets.empty() && meets.top().first <= meetings[i][0])
            {
                int room = meets.top().second;
                meets.pop();
                rooms.emplace(room);
            }

            if (!rooms.empty())
            {
                int room = *rooms.begin();
                rooms.erase(rooms.begin());
                meets.emplace(meetings[i][1], room);
                freq[room]++;
            }

            else
            {
                auto meet = meets.top();
                meets.pop();
                meets.emplace(1LL * meetings[i][1] + meet.first - meetings[i][0], meet.second);
                freq[meet.second]++;
            }
        }

        int maxMeetings = 0, maxMeetingRoom = 0;

        for (int i = 0; i < n; i++)
        {
            if (freq[i] > maxMeetings)
            {
                maxMeetings = freq[i];
                maxMeetingRoom = i;
            }
        }

        return maxMeetingRoom;
    }
};