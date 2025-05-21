class MinStack {
    private int size;
    Node it;
    class Node{
        int data;
        int min;
        Node next;
        Node(int data, int min, Node next){
            this.data = data;
            this.min = min;
            this.next = next;
        }
    }
    
    public MinStack() {
        size = 0;
        Node it = null;
    }
    
    public void push(int val) {
        Node temp = new Node(val, val, null);
        if(it == null){
            it = temp;
            return;
        }
        if(val < it.min){
            temp.min = val;
        }else{
            temp.min = it.min;
        }
        temp.next = it;
        it = temp;
    }
    
    public void pop() {
        if(it == null){
            return;
        }
        Node todelete = it;
        it = it.next;
    }
    
    public int top() {
        if(it != null){
            return it.data;
        }
        return -1;
    }
    
    public int getMin() {
        if(it != null){
            return it.min;
        }
        return -1;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */