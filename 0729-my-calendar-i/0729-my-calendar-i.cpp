class MyCalendar {
public:
    int prev=-1;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(prev>start) return false;
        else prev=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */