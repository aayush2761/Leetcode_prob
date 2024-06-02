class Solution {
public:
    void solve(int total ,unordered_set<int>&st){
      
        for(int i=2; i<=total; i++){
            if(total%i==0){
                st.insert(i);
                while(total%i==0){
                    total/=i;
                }
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int>st;
         
          for(int i=0;i<nums.size();i++){
            solve(nums[i],  st);
          }
       
        return st.size();
    }
};