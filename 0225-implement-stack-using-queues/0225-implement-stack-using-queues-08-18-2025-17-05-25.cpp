class MyStack {
public:
    queue<int>q;
    MyStack() {
        while(!q.empty())q.pop();
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        // queue<int>temp;
        int n = q.size();
        while(n>1){
            q.push(q.front());
            q.pop();
            n--;
        }
        int x= q.front();
        // temp.push(x);
        q.pop();
        // q=temp;
        return x;

    }
    // rotate krde bhai
    int top() {
        // queue<int>temp;
        int n = q.size();
        while(n>1){
           q.push(q.front());
           q.pop();
           n--;
        }
        int x= q.front();
        q.push(x);
        q.pop();
        // q=temp;
        return x;
    }
    
    bool empty() {
        if(q.size()==0) return 1;
        return 0;
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