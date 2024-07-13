// Problem Link :- https://leetcode.com/problems/robot-collisions/

// Solved by Sorting and using Stack
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<pair<int, int>> robots;

        for (int i = 0; i < n; i++)
        {
            pair<int, int> robot = {positions[i], i};
            robots.emplace_back(robot);
        }

        sort(robots.begin(), robots.end());

        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++)
        {
            int position = robots[i].first, index = robots[i].second;
            int health = healths[index], direction = (directions[index] == 'L' ? -1 : 1);
            
            if (st.empty() || st.top().first > 0 == health * direction > 0)
            {
                st.emplace(health * direction, index);
                continue;
            }

            else
            {
                st.emplace(health * direction, index);

                while(st.size() > 1)
                {
                    auto topRobo = st.top();
                    st.pop();
                    auto topNext = st.top();
                    st.pop();

                    if (topNext.first <= topRobo.first || topNext.first > 0 == topRobo.first > 0)
                    {
                        st.emplace(topNext);
                        st.emplace(topRobo);
                        break;
                    }

                    int topHealth = abs(topRobo.first), nextHealth = abs(topNext.first);

                    if (topHealth != nextHealth)
                    {
                        if (topHealth > nextHealth)
                        {
                            int direction = directions[topRobo.second] == 'L' ? -1 : 1;
                            int newHealth = (topHealth - 1) * direction;
                            st.emplace(newHealth, topRobo.second);
                        }

                        else
                        {
                            int direction = directions[topNext.second] == 'L' ? -1 : 1;
                            int newHealth = (nextHealth - 1) * direction;
                            st.emplace(newHealth, topNext.second);
                        }
                    }
                }
            }
        }

        vector<pair<int, int>> remRobots;

        while(!st.empty())
        {
            auto robot = st.top();
            st.pop();
            robot.first = abs(robot.first);
            remRobots.emplace_back(robot);
        }

        sort(remRobots.begin(), remRobots.end(), [&](pair<int, int> robo1, pair<int, int> robo2){
            return robo1.second < robo2.second;
        });

        vector<int> ans;

        for (auto &robot : remRobots)
        {
            ans.emplace_back(robot.first);
        }

        return ans;
    }
};



class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stack;

        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int lhs, int rhs){ 
            return positions[lhs] < positions[rhs]; 
        });

        for (int currentIndex : indices) 
        {
            if (directions[currentIndex] == 'R')
                stack.emplace(currentIndex);
            
            else 
            {
                while (!stack.empty() && healths[currentIndex] > 0) 
                {
                    int topIndex = stack.top();
                    stack.pop();

                    if (healths[topIndex] > healths[currentIndex]) 
                    {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.emplace(topIndex);
                    } 
                    
                    else if (healths[topIndex] < healths[currentIndex]) 
                    {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } 
                    
                    else 
                    {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for (int index = 0; index < n; ++index) 
        {
            if (healths[index] > 0)
                result.push_back(healths[index]);
        }

        return result;
    }
};