class Solution {
public:
    vector<int> leftMax(vector<int>& height){
        int n = height.size();
        stack<int>st;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i]= height[i];
                st.push(height[i]);
            }
            else{
                while(!st.empty() && st.top()<height[i]) st.pop();
                if(!st.empty())res[i]= st.top();
                else {
                    res[i]= height[i];
                    st.push(height[i]);
                }
            }
        }
        return res;
    }
    vector<int> rightMax(vector<int>& height){
        int n = height.size();
        stack<int>st;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]= height[i];
                st.push(height[i]);
            }
            else{
                while(!st.empty() && st.top()<height[i]) st.pop();
                if(!st.empty())res[i]= st.top();
                else {
                    res[i]= height[i];
                    st.push(height[i]);
                }
            }
        }
        return res;
    }
    int trap(vector<int>& height) {
        vector<int>left= leftMax(height);
        vector<int>right= rightMax(height);
        int answer=0;
        for(int i=0;i<height.size();i++){
            int x = min(left[i], right[i]);
            if(x>height[i]){
                answer+= x-height[i];
            }
        }
        return answer;
    }
};