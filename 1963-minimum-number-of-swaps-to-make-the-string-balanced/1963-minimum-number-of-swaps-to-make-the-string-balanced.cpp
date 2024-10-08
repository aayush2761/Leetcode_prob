class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int open=0,close=0,swap=0;
        for(auto i : s){
            if(i=='[') st.push(i);
            else{
                if(!st.empty()) st.pop();
                else swap++;
            }
        }
       
        return ((swap+1)/2);
    }
};