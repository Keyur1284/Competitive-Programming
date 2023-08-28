// Problem Link :- https://leetcode.com/problems/implement-stack-using-queues/

// Solved using queue
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class MyStack {
public:

    queue <int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        
        int size = q.size();
        q.emplace(x);

        for (int i = 0; i < size; i++)
        {
            q.emplace(q.front());
            q.pop();
        }
    }
    
    int pop() {

        int top = q.front();
        q.pop();

        return top;
    }
    
    int top() {

        return q.front();
    }
    
    bool empty() {
        
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */