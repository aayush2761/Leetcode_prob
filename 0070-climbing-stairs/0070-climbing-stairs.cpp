class Solution {
public:
    void  solve(int n , int &count ){
        if(n==0){
            // count=max(temp,count);
            count++;
            return;
        }
        if(n<0) return;
        // one 
        solve(n-1,count);
        solve(n-2,count);

    }
    int climbStairs(int n) {
        int count=0;
        solve(n,count);
        return count;
    }
};