// Problem Link :- https://leetcode.com/problems/find-the-winner-of-an-array-game/

// Solved using queue
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        if (k >= arr.size())
            return *max_element(arr.begin(), arr.end());

        int maxElement = arr[0];
        queue<int> q;

        for (int i = 1; i < arr.size(); i++) 
        {
            maxElement = max(maxElement, arr[i]);
            q.emplace(arr[i]);
        }
        
        int curr = arr[0];
        int winstreak = 0;
        
        while (!q.empty()) 
        {
            int opponent = q.front();
            q.pop();
            
            if (curr > opponent) 
            {
                q.emplace(opponent);
                winstreak++;
            } 
            
            else 
            {
                q.emplace(curr);
                curr = opponent;
                winstreak = 1;
            }
            
            if (winstreak == k || curr == maxElement)
                return curr;
        }
        
        return -1;
    }
};



// Solved without using queue
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        if (k >= arr.size())
            return *max_element(arr.begin(), arr.end());

        int maxElement = *max_element(arr.begin(), arr.end());
        
        int curr = arr[0];
        int winstreak = 0;
        
        for (int i = 1; i < arr.size(); i++)
        {
            int opponent = arr[i];
            
            if (curr > opponent) 
                winstreak++;
            
            else 
            {
                curr = opponent;
                winstreak = 1;
            }
            
            if (winstreak == k || curr == maxElement)
                return curr;
        }
        
        return -1;
    }
};