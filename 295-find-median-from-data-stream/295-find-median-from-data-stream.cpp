class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lsize = mx.size();
        int rsize = mn.size();
        
        if(lsize == 0){
            mx.push(num);
        }else if(lsize == rsize){
            if(num < mn.top()){
                mx.push(num);
            }else{
                int temp = mn.top();
                mn.pop();
                mx.push(temp);
                mn.push(num);
            }
        }else{
            if(rsize == 0){
                if(num > mx.top()){
                    mn.push(num);
                }else{
                    int temp = mx.top();
                    mx.pop();
                    mn.push(temp);
                    mx.push(num);
                }
            }else if(num >= mn.top()){
                mn.push(num);
            }else{
                if(num < mx.top()){
                    int temp = mx.top();
                    mx.pop();
                    mn.push(temp);
                    mx.push(num);
                }else{
                    mn.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        int lsize = mx.size();
        int rsize = mn.size();
        if(lsize > rsize){
            return double(mx.top());
        }else{
            return (double(mx.top()) + double(mn.top()))/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */