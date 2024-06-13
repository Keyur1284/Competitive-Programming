// Problem Link :- https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {

        int n = seats.size(), moves = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for (int i = 0; i < n; i++)
            moves += abs(seats[i] - students[i]);

        return moves;
    }
};



// Solved by Counting Sort
// Time Complexity :- O(n + m)
// Space Complexity :- O(m)

class Solution {
    
private:
    int findMax(const vector<int>& array) {
        
        return *max_element(array.begin(), array.end());
    }

public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {

        int maxPosition = max(findMax(seats), findMax(students));

        vector<int> differences(maxPosition, 0);

        for (auto &position : seats)
            differences[position - 1]++;

        for (auto &position : students)
            differences[position - 1]--;

        int moves = 0, unmatched = 0;
        
        for (auto &difference : differences) 
        {
            moves += abs(unmatched);
            unmatched += difference;
        }

        return moves;
    }
};