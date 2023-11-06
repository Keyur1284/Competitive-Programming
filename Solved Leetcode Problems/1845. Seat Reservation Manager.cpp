// Problem Link :- https://leetcode.com/problems/seat-reservation-manager/

// Solved using min heap
// Time Complexity :- O((m + n) * logn))    m = number of operations
// Space Complexity :- O(n)                 n = number of seats

class SeatManager {
public:

    priority_queue<int, vector<int>, greater<int>> availableSeats;

    SeatManager (int n) 
    {
        for (int seatNumber = 1; seatNumber <= n; ++seatNumber) 
            availableSeats.emplace(seatNumber);
    }

    int reserve() 
    {
        int seatNumber = availableSeats.top();
        availableSeats.pop();
        return seatNumber;
    }

    void unreserve(int seatNumber) {

        availableSeats.push(seatNumber);
    }
};



// Solved using set
// Time Complexity :- O(mlogn)
// Space Complexity :- O(n)

class SeatManager {
public:

    int marker;
    set<int> availableSeats;

    SeatManager (int n) 
    {
        marker = 1;
    }

    int reserve() {
        
        if (!availableSeats.empty()) 
        {
            int seatNumber = *availableSeats.begin();
            availableSeats.erase(availableSeats.begin());
            return seatNumber;
        }

        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    void unreserve(int seatNumber) 
    {
        availableSeats.insert(seatNumber);
    }
};