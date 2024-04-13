// Problem Link :- https://leetcode.com/problems/maximal-rectangle/

// Solved using Monotonic Stack
// Time Complexity :- O(n*m)
// Space Complexity :- O(m)

class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            left[i] = (!st.empty()) ? st.top() + 1 : 0;

            st.emplace(i);
        }

        while(!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            right[i] = (!st.empty()) ? st.top() - 1 : n - 1;

            st.emplace(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int area = (right[i] - left[i] + 1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int ans  = 0;
        vector <int> heights(m, 0);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    heights[j]++;
                
                else
                    heights[j] = 0;
            }
            
            int area = largestRectangleArea (heights);
            ans = max (ans, area);
        }
        
        return ans;
        
    }
};



class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            left[i] = (st.empty()) ? -1 : st.top();
            st.emplace(i);
        }

        while(!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            right[i] = (st.empty()) ? n : st.top();
            st.emplace(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int ans  = 0;
        vector <int> heights(m, 0);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    heights[j]++;
                
                else
                    heights[j] = 0;
            }
            
            int area = largestRectangleArea (heights);
            ans = max (ans, area);
        }
        
        return ans;
        
    }
};