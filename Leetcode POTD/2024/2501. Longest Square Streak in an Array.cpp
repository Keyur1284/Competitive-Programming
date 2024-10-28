// Problem Link :- https://leetcode.com/problems/longest-square-streak-in-an-array/

// Solved using set
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        set<int> numSet;
        int longestStreak = 0;

        for (int current : nums) 
        {

            if (numSet.find(current) != numSet.end())
                continue;

            int streak = current;
            int streakLength = 1;
            
            while (true) 
            {
                if (1LL * streak * streak > 1e5) 
                    break;

                if (binary_search(nums.begin(), nums.end(), streak * streak)) 
                {
                    streak *= streak;
                    numSet.emplace(streak);
                    streakLength++;
                } 
                
                else
                    break;
            }

            longestStreak = max(longestStreak, streakLength);
        }

        return longestStreak < 2 ? -1 : longestStreak;
    }
};



// Solved using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        int longestStreak = 0;
        unordered_set<int> uniqueNumbers(nums.begin(), nums.end());

        for (int startNumber : nums) 
        {
            int currentStreak = 0;
            long long current = startNumber;
            
            while (uniqueNumbers.find(current) != uniqueNumbers.end()) 
            {
                currentStreak++;
                
                if (current * current > 1e5) 
                    break;

                current *= current;
            }

            longestStreak = max(longestStreak, currentStreak);
        }

        return longestStreak < 2 ? -1 : longestStreak;
    }
};



class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        unordered_map<int, int> streakLengths;
        sort(nums.begin(), nums.end());

        for (int number : nums) 
        {
            int root = (int)sqrt(number);
            
            if (root * root == number && streakLengths.find(root) != streakLengths.end())
                streakLengths[number] = streakLengths[root] + 1;
            
            else
                streakLengths[number] = 1;
        }

        int longestStreak = 0;

        for (auto& [key, streakLength] : streakLengths) 
        {
            longestStreak = max(longestStreak, streakLength);
        }

        return longestStreak < 2 ? -1 : longestStreak;
    }
};