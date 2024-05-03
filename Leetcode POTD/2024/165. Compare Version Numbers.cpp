// Problem Link :- https://leetcode.com/problems/compare-version-numbers/

// Solved by Brute Force Approach
// Time Complexity :- O(n + m)
// Space Complexity :- O(1)

class Solution {
public:

    int compareVersion(string version1, string version2) {
        
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;

        while (i < n || j < m)
        {
            int val1 = 0, val2 = 0;

            while (i < n && version1[i] != '.')
            {
                val1 = val1 * 10 + (version1[i] - '0');
                i++;
            }

            while (j < m && version2[j] != '.')
            {
                val2 = val2 * 10 + (version2[j] - '0');
                j++;
            }

            i++;
            j++;

            if (val1 > val2)
                return 1;

            else if (val1 < val2)
                return -1;
        }

        return 0;
    }
};



// Solved using stringstream
// Time Complexity :- O(n + m)
// Space Complexity :- O(1)

class Solution {
public:

    int compareVersion(string version1, string version2) {
        
        stringstream ss1(version1);
        stringstream ss2(version2);
        string token1, token2;

        while (true) 
        {
            bool flag1 = false, flag2 = false;
            int val1 = 0, val2 = 0;

            if (getline(ss1, token1, '.')) 
                flag1 = true;
            
            if (getline(ss2, token2, '.')) 
                flag2 = true;
            
            if (flag1) 
                val1 = stoi(token1);

            if (flag2) 
                val2 = stoi(token2);

            if (val1 > val2)
                return 1;

            else if (val1 < val2)
                return -1;   
            
            else if (!flag1 && !flag2)
                break;
        }

        return 0;
    }
};