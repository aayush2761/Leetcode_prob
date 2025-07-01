class Solution {
public:
    void left (vector<int>&leftMin, int n ,vector<int>& target ){
        stack<int>st;
        int i=0;
        while(i<n){
            while(!st.empty() && st.top()>target[i]){
                st.pop();
            }
            if(st.empty()){
                leftMin[i]= 0;
            }
            else leftMin[i]= st.top();
             st.push(target[i]);
            i++;
        }

    }
    void right (vector<int>&rightMin, int n ,vector<int>& target ){
         stack<int>st;
        int i=n-1;
        while(i>=0){
             while(!st.empty() && st.top()>=target[i]){
                 st.pop();
             }
             if(st.empty())rightMin[i]=0;
             else rightMin[i]= st.top();
              st.push(target[i]);
            i--;
        }
    }
    int minNumberOperations(vector<int>& target) {
        int n= target.size();
        vector<int>leftMin(n,INT_MIN), rightMin(n,INT_MIN);
        left(leftMin, n, target);
        right(rightMin, n, target);
        int res=0;
        for(int i=0;i<n;i++){
            res+= target[i]- max({leftMin[i], rightMin[i]});
        }
        return res;

    }
};