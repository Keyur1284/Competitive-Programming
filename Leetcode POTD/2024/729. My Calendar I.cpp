// Problem Link :- https://leetcode.com/problems/my-calendar-i/

// Solved by Brute Force Approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class MyCalendar {
private:
    
    vector<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        
        for (auto &[s, e] : calendar) 
        {
            if (start < e && s < end)
                return false;
        }
        
        calendar.emplace_back(start, end);
        return true;
    }
};



// Solved using set
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class MyCalendar {
private:
    
    set<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        
        pair<int, int> event{start, end};
        auto nextEvent = calendar.lower_bound(event);
        
        if (nextEvent != calendar.end() && nextEvent->first < end)
            return false;

        if (nextEvent != calendar.begin()) 
        {
            auto prevEvent = prev(nextEvent);
            
            if (prevEvent->second > start)
                return false;
        }

        calendar.emplace(event);
        return true;
    }
};



// Solved using map
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class MyCalendar {
private:
    
    map<int, int> calendar;

public:
    bool book(int start, int end) {
        
        auto nextEvent = calendar.lower_bound(start);
        
        if (nextEvent != calendar.end() && nextEvent->first < end)
            return false;

        if (nextEvent != calendar.begin()) 
        {
            auto prevEvent = prev(nextEvent);
            
            if (prevEvent->second > start)
                return false;
        }

        calendar[start] = end;
        return true;
    }
};