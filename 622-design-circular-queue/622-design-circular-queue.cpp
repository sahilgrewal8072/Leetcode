class MyCircularQueue {
public:
    vector<int> q;
    int f;
    int r;
    int sz;
    MyCircularQueue(int k) {
        q.resize(k, -1);
        f = 0;
        r = 0;
        sz = k;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        q[r] = value;
        r = (r + 1)%sz;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        q[f] = -1;
         f = (f + 1)%sz;
        return true;
    }
    
    int Front() {
        return q[f];
    }
    
    int Rear() {
      int x = ((r-1) == -1) ? sz-1 : r - 1;
        return q[x];
    }
    
    bool isEmpty() {
        if(f == r && q[f] == -1)return true;
        return false;
    }
    
    bool isFull() {
        if(f == r && q[f] != -1) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */