// Problem Link :- https://leetcode.com/problems/number-of-senior-citizens/

// Solved by character extraction
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int count = 0;

        for (auto &it : details)
        {
            count += ((it[11] - '0') * 10 + (it[12] - '0') > 60);
        }

        return count;
    }
};



class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int count = 0;

        for (auto &it : details)
        {
            count += (stoi(it.substr(11, 2)) > 60);
        }

        return count;
    }
};