//Problem Link :- https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    
    int largestRectangleArea (vector <int> &heights)
    {
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