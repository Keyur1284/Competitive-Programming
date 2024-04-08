// Problem Link :- https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

// Solved by simulation
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int n = students.size();
        queue<int> stu;

        for (auto &it : students)
            stu.emplace(it);

        int sandwich = 0;

        while (!stu.empty())
        {
            int size = stu.size();
            bool flag = false;

            while (size--)
            {
                int top = stu.front();
                stu.pop();

                if (top == sandwiches[sandwich])
                    flag = true, sandwich++;

                else
                    stu.emplace(top);
            }

            if (!flag)
                return (int)stu.size();
        }

        return 0;

    }
};



// Solved by counting
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int n = students.size();
        int count[2] = {0};

        for (auto &it : students)
            count[it]++;

        for (auto &it : sandwiches)
        {
            if (count[it] == 0)
                return n;

            count[it]--;
            n--;
        }

        return 0;
    }
};