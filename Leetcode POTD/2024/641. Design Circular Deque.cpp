// Problem Link :- https://leetcode.com/problems/design-circular-deque/

// Solved using Doubly Linked List
// Time Complexity :- O(1)
// Space Complexity :- O(k)

struct Node {
    
    int val;
    Node* next, *prev;
    
    Node(int val, Node* next = NULL, Node* prev = NULL)
    {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class MyCircularDeque {
private:
    
    Node* head, *rear;
    int size, capacity;

public:
    
    MyCircularDeque(int k) {
        head = NULL;
        rear = NULL;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        
        if (isFull()) 
            return false;
        
        if (head == NULL) 
        {
            head = new Node(value);
            rear = head;
        } 
        
        else 
        {
            Node* newHead = new Node(value, head);
            head->prev = newHead;
            head = newHead;
        }

        size++;
        return true;
    }

    bool insertLast(int value) {
        
        if (isFull()) 
            return false;
        
        if (head == NULL) 
        {
            head = new Node(value);
            rear = head;
        } 
        
        else 
        {
            Node* newNode = new Node(value, NULL, rear);
            rear->next = newNode;
            rear = newNode;
        }

        size++;
        return true;
    }

    bool deleteFront() {
        
        if (isEmpty()) 
            return false;
        
        if (size == 1) 
        {
            head = NULL;
            rear = NULL;
        } 
        
        else 
        {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
        }

        size--;
        return true;
    }

    bool deleteLast() {
        
        if (isEmpty()) 
            return false;

        if (size == 1) 
        {
            head = NULL;
            rear = NULL;
        } 
        
        else 
        {
            Node* prevNode = rear->prev;
            delete rear;
            rear = prevNode;
        }

        size--;
        return true;
    }

    int getFront() { 
        return (isEmpty()) ? -1 : head->val; 
    }

    int getRear() { 
        return (isEmpty()) ? -1 : rear->val; 
    }

    bool isEmpty() { 
        return size == 0; 
    }

    bool isFull() { 
        return size == capacity; 
    }
};



// Solved using Circular Array
// Time Complexity :- O(1)
// Space Complexity :- O(k)

class MyCircularDeque {
private:
    
    vector<int> queue;
    int front, rear, size, capacity;

public:
    
    MyCircularDeque(int k) {
        queue.resize(k);
        size = 0;
        capacity = k;
        front = 0;
        rear = k - 1;
    }

    bool insertFront(int value) {
        
        if (isFull()) 
            return false;
        
        front = (front - 1 + capacity) % capacity;
        queue[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        
        if (isFull()) 
            return false;
        
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        
        if (isEmpty()) 
            return false;
        
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        
        if (isEmpty()) 
            return false;
        
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        
        if (isEmpty()) 
            return -1;
        
        return queue[front];
    }

    int getRear() {
        
        if (isEmpty()) 
            return -1;
        
        return queue[rear];
    }

    bool isEmpty() { 
        return size == 0; 
    }

    bool isFull() { 
        return size == capacity; 
    }
};