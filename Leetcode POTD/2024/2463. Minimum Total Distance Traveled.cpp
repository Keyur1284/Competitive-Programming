// Problem Link :- https://leetcode.com/problems/minimum-total-distance-traveled/

// Solved by Memoization Method
// Time Complexity :- O(n^2 * m)    n = no. of robots
// Space Complexity :- O(n * m)     m = no. of factories

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPositions;
        
        for (auto &fact : factory)
        {
            for (int i = 0; i < fact[1]; i++) 
            {
                factoryPositions.emplace_back(fact[0]);
            }
        }

        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<vector<long long>> dp(robotCount, vector<long long>(factoryCount, -1));

        return calculateMinDistance(0, 0, robot, factoryPositions, dp);
    }

    long long calculateMinDistance(int robotIdx, int factoryIdx, vector<int>& robot, vector<int>& factoryPositions, vector<vector<long long>>& dp) {

        if (robotIdx == robot.size()) 
            return 0;

        if (factoryIdx == factoryPositions.size()) 
            return 1e12;

        if (dp[robotIdx][factoryIdx] != -1) 
            return dp[robotIdx][factoryIdx];

        long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) + calculateMinDistance(robotIdx + 1, factoryIdx + 1, robot, factoryPositions, dp);
        long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot, factoryPositions, dp);

        return dp[robotIdx][factoryIdx] = min(assign, skip);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2 * m)    n = no. of robots
// Space Complexity :- O(n * m)     m = no. of factories

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPositions;
        
        for (auto &fact : factory)
        {
            for (int i = 0; i < fact[1]; i++) 
            {
                factoryPositions.emplace_back(fact[0]);
            }
        }

        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<vector<long long>> dp(robotCount + 1, vector<long long>(factoryCount + 1, 0));

        for (int i = 0; i < robotCount; i++)
            dp[i][factoryCount] = 1e12;

        for (int i = robotCount - 1; i >= 0; i--) 
        {
            for (int j = factoryCount - 1; j >= 0; j--) 
            {
                long long assign = abs(robot[i] - factoryPositions[j]) + dp[i + 1][j + 1];
                long long skip = dp[i][j + 1];

                dp[i][j] = min(assign, skip);
            }
        }

        return dp[0][0];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n^2 * m)    n = no. of robots
// Space Complexity :- O(m)         m = no. of factories

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPosition;
        
        for (auto &fact : factory)
        {
            for (int i = 0; i < fact[1]; i++) 
            {
                factoryPosition.emplace_back(fact[0]);
            }
        }

        int robotCount = robot.size(), factoryCount = factoryPosition.size();
        vector<long long> dp(factoryCount + 1, 0);

        for (int i = robotCount - 1; i >= 0; i--)
        {
            if (i != robotCount - 1)
                dp[factoryCount] = 1e12;

            vector<long long> temp(factoryCount + 1, 0);
            temp[factoryCount] = 1e12;

            for (int j = factoryCount - 1; j >= 0; j--)
            {
                long long assign = abs(robot[i] - factoryPosition[j]) + dp[j + 1];
                long long skip = temp[j + 1];

                temp[j] = min(assign, skip);
            }

            dp = temp;
        }

        return dp[0];
    }
};