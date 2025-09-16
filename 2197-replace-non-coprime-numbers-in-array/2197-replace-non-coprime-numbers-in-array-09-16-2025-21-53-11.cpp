class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long >st;
        for(int i=0;i<nums.size();i++){
            long long curr= nums[i]; // loop this for 0 to n-1th index 

            while(!st.empty()){   // foreach index check the subsequent left element in the stack 

                long long x = st.top(); 
                long long gcd = __gcd(x,curr);
                if(gcd>1){
                    st.pop();
                    curr = (x*curr) / gcd;
                    // st.push(curr);
                }
                else break;

            }
            st.push(curr);
        }



        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};