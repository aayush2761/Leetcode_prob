class MyCalendarThree {
public:
   map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum=0;
        int res=0;
        for(auto &i : mp){
            sum+=i.second;
            // if(sum>2){
            //     mp[start]--;
            //     mp[end]++;
            //     // return false;
            // }
            // else
            res=max(sum,res);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */