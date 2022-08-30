class MyQueue {
public:
    // amortized O(1) Solution.
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int x = peek();
        output.pop();
        return x;
    }
    
    int peek() {
        if(output.size() == 0){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        
        return output.top();
    }
    
    bool empty() {
        if(input.size() == 0 && output.size() == 0)return true;
        return false;
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