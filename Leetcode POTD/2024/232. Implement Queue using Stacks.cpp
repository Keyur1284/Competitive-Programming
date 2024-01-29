// Problem Link :- https://leetcode.com/problems/implement-queue-using-stacks/

// Solved using 2 stacks
// Time Complexity :- O(1) for push and O(n) for pop and peek
// Space Complexity :- O(n)

class MyQueue {
public:

    stack<int> input, output;

    MyQueue() {
        
    }
    
    void push(int x) {
        
        input.emplace(x);
    }
    
    int pop() {
        
        if (output.empty())
        {
            while(!input.empty())
            {
                output.emplace(input.top());
                input.pop();
            }
        }

        int ans = output.top();
        output.pop();

        return ans;
    }
    
    int peek() {
        
        if (output.empty())
        {
            while(!input.empty())
            {
                output.emplace(input.top());
                input.pop();
            }
        }

        return output.top();
    }
    
    bool empty() {
        
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */