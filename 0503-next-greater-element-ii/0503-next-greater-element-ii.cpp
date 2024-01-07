class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                    //stack is not empty
                    if(st.empty()==false){
                        ans[i]=st.top();
                    }
                    //stack is empty here 
                    else{
                        ans[i]=-1;
                    }
                }
                //here pushing the greater to the stack 
            st.push(nums[i%n]);
        }
        return ans;
    }
};