class MyStack {
private:
    int h;
    int *st;
    
public:
    MyStack() {
        h=-1;
        st=new int[10000];
    }
    
    void push(int x) {
        st[++h]=x;
    }
    
    int pop() {
        // if (top==-1) return false;
        int res=st[h];
        h--;
        return res;
    }
    
    int top() {
        return st[h];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (h==-1) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
