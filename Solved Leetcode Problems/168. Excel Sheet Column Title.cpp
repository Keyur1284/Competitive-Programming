// Problem Link :- https://leetcode.com/problems/excel-sheet-column-title/

// Solved by Math
// Time Complexity :- O(log_26(n))
// Space Complexity :- O(1)

class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string title = "";

        while (columnNumber)
        {
            columnNumber--;

            title += ('A' + columnNumber % 26);
            columnNumber /= 26;
        }

        reverse(title.begin(), title.end());
        return title;
    }
};