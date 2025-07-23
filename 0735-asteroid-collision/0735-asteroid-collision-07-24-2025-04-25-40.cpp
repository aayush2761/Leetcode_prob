class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        stack<int>back;
        for(int i=0;i<a.size();i++){
            if(st.empty() && a[i]<0){
                back.push(a[i]);
                continue;
            }
            if(a[i]>0) st.push(a[i]);
            else {
                while(!st.empty() && abs(a[i])>= st.top()){
                    int x= st.top();
                    st.pop();
                    if(st.empty() && abs(a[i])!=x)back.push(a[i]);
                    if(abs(a[i])==x) break;
                }
            }
        }
        vector<int>b;
        while(!back.empty()){
            b.push_back(back.top());
            back.pop();
        }
         reverse(b.begin(), b.end());
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        for(int i=0;i<res.size();i++) b.push_back(res[i]);
        return b;
    }
};