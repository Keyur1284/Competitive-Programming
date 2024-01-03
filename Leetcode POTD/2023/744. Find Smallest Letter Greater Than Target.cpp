// Problem Link :- https://leetcode.com/problems/find-smallest-letter-greater-than-target/

// Solved by inbuilt upper_bound function
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int index = upper_bound(letters.begin(), letters.end(), target) - letters.begin();

        return letters[index % letters.size()];
    }
};



// Solved by Binary Search
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int low = 0, high = letters.size() - 1, mid, ans = 0;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (letters[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return letters[ans];
    }
};