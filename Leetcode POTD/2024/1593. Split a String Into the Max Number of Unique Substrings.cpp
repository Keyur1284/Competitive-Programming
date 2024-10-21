// Problem Link :- https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

// Solved by Backtracking
// Time Complexity :- O(2^n)
// Space Complexity :- O(n)

class Solution {
public:
    int maxUniqueSplit(string s) {

        int n = s.length();
        unordered_set<string> vis;
        return backtrack(0, n, vis, s);
    }

private:
    int backtrack(int start, int n, unordered_set<string> &vis, string &s) {

        if (start == n) 
            return 0;

        int maxCount = 0;
        
        for (int end = start + 1; end <= n; end++) 
        {
            string substring = s.substr(start, end - start);

            if (vis.find(substring) == vis.end()) 
            {
                vis.insert(substring);
                maxCount = max(maxCount, 1 + backtrack(end, n, vis, s));
                vis.erase(substring);
            }
        }

        return maxCount;
    }
};



class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        int maxCount = 0;
        backtrack(s, 0, seen, 0, maxCount);
        return maxCount;
    }

private:
    void backtrack(const string& s, int start, unordered_set<string>& seen, int count, int& maxCount) {
        
        if (count + (s.size() - start) <= maxCount) 
            return;

        if (start == s.size()) 
        {
            maxCount = max(maxCount, count);
            return;
        }

        for (int end = start + 1; end <= s.size(); ++end) 
        {
            string substring = s.substr(start, end - start);
            
            if (seen.find(substring) == seen.end()) 
            {
                seen.insert(substring);
                backtrack(s, end, seen, count + 1, maxCount);
                seen.erase(substring);
            }
        }
    }
};