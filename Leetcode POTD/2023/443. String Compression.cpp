// Problem Link :- https://leetcode.com/problems/string-compression

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int ans = 0, index = 0, n = chars.size();

        while (index < n)
        {
            int currLen = 1;

            while (index + currLen < n && chars[index] == chars[index + currLen])
                currLen++;

            chars[ans++] = chars[index];
            index += currLen;

            if (currLen > 1)
            {
                for (auto &it : to_string(currLen))
                    chars[ans++] = it;
            }
        }

        return ans;
    }
};