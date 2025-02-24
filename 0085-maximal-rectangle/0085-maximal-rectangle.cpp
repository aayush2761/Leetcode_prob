class Solution {
public:
    vector<int>prev(vector<int>& nums){
        vector<int>res;
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()){
                if(nums[st.top()]>=nums[i])st.pop();
                else break;
            }
            if(!st.empty())res.push_back(st.top());
            else res.push_back(-1);
             st.push(i);
        }
        return res;
    }
    vector<int>next(vector<int>& nums){
        int n =nums.size();
        // int inf=n+1;
        vector<int>res(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(nums[st.top()]>=nums[i])st.pop();
                else break;
            }
             if(!st.empty())res[i]=st.top();
            else res[i]=n;
             st.push(i);
        }
        return res;

    }
    int largestRectangleArea(vector<int>& nums) {
        vector<int>prevSmaller= prev(nums);
        vector<int>nextsmaller= next(nums);
        int res=0;
        for(int i=0;i<nums.size();i++){
            res=max(res,(nextsmaller[i]-prevSmaller[i]-1)*nums[i] );
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res=0;
        vector<int>temp(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[j]+=matrix[i][j]-'0';
            }
            res=max(res,largestRectangleArea(temp));
        }
        return res;
    }
};