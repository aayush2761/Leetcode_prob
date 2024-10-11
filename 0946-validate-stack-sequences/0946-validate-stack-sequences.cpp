class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int>st;
        while(i<pushed.size()){
            if( !st.empty() && st.top()==popped[j] ){
                st.pop();
                j++;
            }
            else{
                st.push(pushed[i]);
                i++;
            }
        }
        while(j<popped.size()){
            if( !st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
            else return false;
        }
        return true;
    }
};