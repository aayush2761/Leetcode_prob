class Solution {
public:
    int numSteps(string s) {
            int l= s.size()-1;
        int carry=0;
        int count=0;
        while(l>0){
            // check for even number 
            if(s[l]-'0' + carry == 0){
                count+=1;
                carry=0;
            }
            // carry==0 && s[l]==1---> odd
            // carry==1 && s[l]==0 --> odd
            else if(s[l]-'0' + carry==1){
                carry=1;
                count+=2;
            }
            // carry==1 && s[l]==1 ---> odd + 1=even and chop off last digit bhy transferring 1 to carry
            else{
                carry=1;
                count+=1;
            }
          l--;
        }
          // still carry is 1 so add last digit to 1 + 1 -->10
            if(carry==1) count+=1;
            return count;
    }
};