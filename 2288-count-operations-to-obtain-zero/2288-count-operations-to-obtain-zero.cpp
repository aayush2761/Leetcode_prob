class Solution {
public:
    int ans=0; 
    int countOperations(int num1, int num2) {
       if(num1==0 || num2==0) return ans;
       if(num1>=num2){
           num1=num1-num2;
           ans++;
           countOperations( num1, num2);
       } 
       else{
           num2=num2-num1;
           ans++;
           countOperations( num1, num2);
       } 
       return ans;
    }
};