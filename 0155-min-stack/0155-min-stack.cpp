class MinStack {
public:
vector<pair<int,int>>vec;
int mini=INT_MAX;
int index=-1;

    MinStack() {
        
    }
    
    void push(int val) {
        mini=min(mini,val);
        vec.push_back({val,mini});
        index++;
    }
    
    void pop() {
    
        vec.pop_back();
    }
    
    int top() {
        if(index<0) return -1;
        auto i = vec.back();
        return i.first;

    }
    
    int getMin() {
        if(index<0) return -1;
          auto i = vec.back();
        return i.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */