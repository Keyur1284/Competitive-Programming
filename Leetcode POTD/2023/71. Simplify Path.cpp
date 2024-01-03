// Problem Link :- https://leetcode.com/problems/simplify-path/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string simplifyPath(string path) {
        
        stringstream ss(path);
        vector<string> simplified;
        string temp;

        while (getline(ss, temp, '/'))
        {
            if (temp == ".." && simplified.size())
                simplified.pop_back();

            else if (temp != "" && temp != "." && temp != "..")
                simplified.emplace_back(temp);
        }

        string simplifiedPath = "";

        for (auto &st : simplified)
            simplifiedPath += "/" + st;

        return (simplifiedPath.size()) ? simplifiedPath : "/";
    }
};


class Solution {
public:
    string simplifyPath(string path) {
        
        int n = path.size();
        string ans = "";
        stack<string> dirFiles;

        for (int i = 0; i < n; i++)
        {
            if (path[i] == '/')
                continue;

            string temp = "";

            while (i < n && path[i] != '/')
                temp += path[i++];

            if (temp == ".")
                continue;

            if (temp == ".." && dirFiles.size())
                dirFiles.pop();

            else if (temp != "..")
                dirFiles.emplace(temp);
        }

        while (!dirFiles.empty())
        {
            ans = "/" + dirFiles.top() + ans;
            dirFiles.pop();
        }

        return (ans.size()) ? ans : "/";
    }
};