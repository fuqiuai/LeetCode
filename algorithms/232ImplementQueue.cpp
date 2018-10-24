class MyQueue {
    int h;
    int *qu;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        h=-1;
        qu=new int[10000];
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        qu[++h]=x;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res=qu[0];
        h--;
        for (int i=0;i<=h;i++)
            qu[i]=qu[i+1];
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return qu[0];
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (h==-1) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
