//Problem Link :- https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector <int> right(n), left(n);
        stack <int> st;
        
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty())
                left[i] = 0;
            
            else
                left[i] = st.top() + 1;
            
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if (st.empty())
                right[i] = n - 1;
            
            else
                right[i] = st.top() - 1;
            
            st.push(i);
        }
        
        int maxi = INT_MIN;
        
        for (int i = 0; i < n; i++)
            maxi = max(maxi, (right[i] - left[i] + 1) * heights[i]);
        
        return maxi;
    }
};


//Optimized Solution

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size(), maxi = 0;
        stack <int> st;
        
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        
            {            
                int height = heights[st.top()];
                st.pop();
                int width;

                if (st.empty())
                    width = i;

                else
                    width = i - st.top() - 1;

                maxi = max (maxi, height * width);
            }
            
            st.emplace(i);
        }
        
        return maxi;
    }
};