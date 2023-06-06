//Problem Link :- https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003


//Solved by Memoization Method
int func (int day, int last, vector <vector<int>> &dp, vector<vector<int>> &points)
{
    if (dp[day][last] != -1)
        return dp[day][last];
    
    if (day == 0)
    {
        int maxi = 0;
        
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
                maxi = max(maxi, points[day][task]);
        }
        
        return dp[day][last] = maxi;
    }
    
    int maxi = 0;
    
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int score = points[day][task] + func(day - 1, task, dp, points);
            maxi = max (maxi, score);
        }
    }
    
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector <vector<int>> dp(n, vector <int> (4, -1));
    return func (n - 1, 3, dp, points);
}



int func (int day, int last, vector <vector<int>> &dp, vector<vector<int>> &points)
{
    if (day < 0)
        return 0;

    if (dp[day][last] != -1)
        return dp[day][last];
    
    int maxi = 0;
    
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int score = points[day][task] + func(day - 1, task, dp, points);
            maxi = max (maxi, score);
        }
    }
    
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector <vector<int>> dp(n, vector <int> (4, -1));
    return func (n - 1, 3, dp, points);
}



//Solved by Tabulation Method
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector <vector<int>> dp(n, vector <int> (4, -1));
    
    dp[0][0] = max (points[0][1], points[0][2]);
    dp[0][1] = max (points[0][0], points[0][2]);
    dp[0][2] = max (points[0][0], points[0][1]);
    dp[0][3] = max (points[0][0], max(points[0][1], points[0][2]));
    
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int score = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], score);
                }
            }      
        }
    }
    
    return dp[n - 1][3];
}


//Solved by Tabulation Method (Space Optimized)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector <int> dp(4, -1);
    
    dp[0] = max (points[0][1], points[0][2]);
    dp[1] = max (points[0][0], points[0][2]);
    dp[2] = max (points[0][0], points[0][1]);
    dp[3] = max (points[0][0], max(points[0][1], points[0][2]));
    
    for (int day = 1; day < n; day++)
    {
        vector <int> temp(4, -1);

        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int score = points[day][task] + dp[task];
                    temp[last] = max(temp[last], score);
                }
            }      
        }
        
        dp = temp;
    }
    
    return dp[3];
}
