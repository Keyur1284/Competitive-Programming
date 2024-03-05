// Problem Link :- https://leetcode.com/problems/race-car/

// Solved by DP
// Time Complexity :- O(target * log(target))
// Space Complexity :- O(target)

class Solution {
public:
    int racecar(int target) {

        vector<int> dp(target + 1, -1);
        
        function<int(int)> solve = [&](int target) -> int {

            if (dp[target] != -1)
                return dp[target];

            int steps = log2(target) + 1;

            if ((1 << steps) - 1 == target)
                return dp[target] = steps;

            else
            {
                // Go beyond target
                dp[target] = solve((1 << steps) - 1 - target) + steps + 1;

                for (int pos = 0; pos < steps - 1; pos++)
                {
                    // Go uptil max power of 2 which is less than target
                    // and then go in back direction thereby again increasing distance
                    int ans = solve(target - (1 << (steps - 1)) + (1 << pos)) + (steps - 1 + 1) + (pos + 1);
                    dp[target] = min(dp[target], ans);
                }

                return dp[target];
            }
        };

        return solve(target);   
    }
};



// Solved by BFS
// Time Complexity :- O(target * log(target))
// Space Complexity :- O(target)

class Solution {
public:

    struct Node
    {
        int pos, speed, steps;
        
        Node(int pos, int speed, int steps) 
        {
            this->pos = pos;
            this->speed = speed;
            this->steps = steps;
        }
    };

    int racecar(int target) {

        queue<Node> BFS;
        BFS.emplace(Node(0, 1, 0));

        while (!BFS.empty())
        {
            Node curr = BFS.front();
            BFS.pop();

            int steps = curr.steps, pos = curr.pos, speed = curr.speed;

            if (pos == target)
                return steps;

            if (pos < 0 || pos > 2 * target)
                continue;

            BFS.emplace(Node(pos + speed, speed * 2, steps + 1));
            
            if (pos + speed > target && speed > 0)
                BFS.emplace(Node(pos, -1, steps + 1));
            
            else if (pos + speed < target && speed < 0)
                BFS.emplace(Node(pos, 1, steps + 1));
        }   

        return -1;
    }

};