class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& s, int k) {
        vector<int> res;
        priority_queue<int>main, side;
        int i=0,j=0;
        while(i<s.size()){
            main.push(s[i]);
            if(i-j+1==k){
                if(!side.empty()){
                    while(side.top()== main.top()){
                        side.pop();
                        main.pop();
                        if(side.empty())break;
                    }
                }
                res.push_back(main.top());
                side.push(s[j]);
                j++;
            }
            i++;
        }
        return res;

    }
};