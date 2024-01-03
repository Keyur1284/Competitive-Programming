// Problem Link :- https://leetcode.com/problems/path-crossing/

// Solved using set
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    bool isPathCrossing(string path) {
        
        int x = 0, y = 0;
        set<pair<int, int>> vis;
        vis.insert({x, y});

        unordered_map<char, pair<int, int>> moves;
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};
        moves['W'] = {-1, 0};
        moves['E'] = {1, 0};

        for (auto &c : path) 
        {
            auto curr = moves[c];
            int dx = curr.first, dy = curr.second;
            x += dx;
            y += dy;

            if (vis.find({x, y}) != vis.end()) 
                return true;
                
            vis.insert({x, y});
        }

        return false;
    }
};



// Solved using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool isPathCrossing(string path) {
        
        int x = 0, y = 0;
        unordered_set<string> vis;
        vis.insert("0,0");

        unordered_map<char, pair<int, int>> moves;
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};
        moves['W'] = {-1, 0};
        moves['E'] = {1, 0};

        for (auto &c : path) 
        {
            auto curr = moves[c];
            int dx = curr.first, dy = curr.second;
            x += dx;
            y += dy;

            string hash = to_string(x) + "," + to_string(y);

            if (vis.find(hash) != vis.end())
                return true;
            
            vis.insert(hash);
        }

        return false;
    }
};