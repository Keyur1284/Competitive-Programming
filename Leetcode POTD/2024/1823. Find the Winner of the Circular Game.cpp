// Problem Link :- https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Solved by Simulation of Circular Array
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int findTheWinner(int n, int k) {

        vector<int> circle(n);
        iota(circle.begin(), circle.end(), 1);

        int startIndex = 0;

        while (circle.size() > 1)
        {
            int removalIndex = (startIndex + k - 1) % circle.size();
            circle.erase(circle.begin() + removalIndex);
            startIndex = removalIndex;
        }

        return circle.front();
    }
};



// Solved by Simulation of Queue
// Time Complexity :- O(n * k)
// Space Complexity :- O(n)

class Solution {
public:
    int findTheWinner(int n, int k) {

        queue<int> circle;
        for (int i = 1; i <= n; i++) 
            circle.emplace(i);


        while (circle.size() > 1) 
        {
            for (int i = 0; i < k - 1; i++) 
            {
                circle.emplace(circle.front());
                circle.pop();
            }

            circle.pop();
        }

        return circle.front();
    }
};



// Solved by Recursion
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    
    int findTheWinner(int n, int k) { 
        return winnerHelper(n, k) + 1; 
    }

private:
    int winnerHelper(int n, int k) {
        if (n == 1) 
            return 0;
        
        return (winnerHelper(n - 1, k) + k) % n;
    }
};



// Solved by Iterative Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int findTheWinner(int n, int k) {
        
        int ans = 0;
        
        for (int i = 2; i <= n; i++) 
        {
            ans = (ans + k) % i;
        }

        return ans + 1;
    }
};