class MinStack {
private:
    int h;
    int *st;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        h=-1;
        st=new int[10000];
    }
    
    void push(int x) {
        st[++h]=x;
    }
    
    void pop() {
        // if (top==-1) return false;
        h--;
    }
    
    int top() {
        return st[h];
    }
    
    int getMin() {
        int temp=INT_MAX;
        for (int i=0;i<=h;i++)
            temp=min(temp,st[i]);
        return temp;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
