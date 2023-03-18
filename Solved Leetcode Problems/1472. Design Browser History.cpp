// Problem Link :- https://leetcode.com/problems/design-browser-history/

// n visit calls are made, m is the maximum number of steps to go forward or back, 
// and l is the maximum length of the URL string.
// Time Complexity :- O(min(m,n))
// Space Complexity :- O(l⋅n)

// Solved using two stacks

class BrowserHistory {
public:

    string current;
    stack<string> history, future;

    BrowserHistory(string homepage) {
        
        current = homepage;
    }
    
    void visit(string url) {
        
        history.emplace(current);
        current = url;
        future = stack<string>();
    }
    
    string back(int steps) {
        
        while(!history.empty() && steps--)
        {
            future.emplace(current);
            current = history.top();
            history.pop();
        }

        return current;
    }
    
    string forward(int steps) {
        
        while(!future.empty() && steps--)
        {
            history.emplace(current);
            current = future.top();
            future.pop();
        }

        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


// Solved using doubly linked list

class DLL {
public:

    string data;
    DLL *prev, *next;

    DLL (string url)
    {
        data = url;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:

    DLL *head, *tail;

    BrowserHistory(string homepage) {
        
        head = new DLL(homepage);
        tail = head;
    }
    
    void visit(string url) {
        
        DLL *newNode = new DLL(url);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
    string back(int steps) {
        
        while (tail->prev != NULL && steps--)
            tail = tail->prev;

        return tail->data;
    }
    
    string forward(int steps) {
        
        while (tail->next != NULL && steps--)
            tail = tail->next;

        return tail->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


// Solved using vector

// Time Complexity :- O(1)
// Space Complexity :- O(l⋅n)

class BrowserHistory {
public:

    vector<string> visited;
    int curr, tail;

    BrowserHistory(string homepage) {
        
        visited.emplace_back(homepage);
        curr = 0;
        tail = 0;
    }
    
    void visit(string url) {
        
        curr++;

        if (visited.size() > curr)
            visited[curr] = url;

        else
            visited.emplace_back(url);

        tail = curr;

    }
    
    string back(int steps) {
        
        curr = max(0, curr - steps);
        return visited[curr];

    }
    
    string forward(int steps) {
        
        curr = min(tail, curr + steps);
        return visited[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
