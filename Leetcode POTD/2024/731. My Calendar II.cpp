// Problem Link :- https://leetcode.com/problems/my-calendar-ii/

// Solved by Brute Force Approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class MyCalendarTwo {
public:
    
    vector<pair<int, int>> bookings, overlapBookings;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        
        for (auto booking : overlapBookings) 
        {
            if (doesOverlap(booking.first, booking.second, start, end))
                return false;
        }

        for (auto booking : bookings) 
        {
            if (doesOverlap(booking.first, booking.second, start, end)) 
                overlapBookings.emplace_back(getOverlapped(booking.first, booking.second, start, end));
        }

        bookings.emplace_back(start, end);
        return true;
    }

private:

    bool doesOverlap(int start1, int end1, int start2, int end2) 
    {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) 
    {
        return {max(start1, start2), min(end1, end2)};
    }
};



// Solved by Line Sweep using map
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class MyCalendarTwo {
public:

    map<int, int> bookingCount;
    int maxOverlappedBooking;

    MyCalendarTwo() { 
        maxOverlappedBooking = 2; 
    }

    bool book(int start, int end) {
        
        bookingCount[start]++;
        bookingCount[end]--;

        int overlappedBooking = 0;

        for (auto bookings : bookingCount) 
        {    
            overlappedBooking += bookings.second;

            if (overlappedBooking > maxOverlappedBooking) 
            {
                bookingCount[start]--;
                bookingCount[end]++;

                if (bookingCount[start] == 0)
                    bookingCount.erase(start);
                
                if (bookingCount[end] == 0)
                    bookingCount.erase(end);

                return false;
            }
        }

        return true;
    }
};