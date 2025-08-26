class Solution {
public:
    int front(string s){
        int ans=0;
        int start=0;
        int count=0;
        for(int end=0;end<s.size();end++){
            if(s[end]=='('){
                count++;
            }
            else count--;

            if(count==0){
                ans= max(ans, end-start+1);
            }
            if(count<0){
                start= end+1;
                count=0;
            }
        }
        return ans;
    }
    int back(string s){
        int ans=0;
        int end=s.size()-1;
        int count=0;
        for(int start=s.size()-1;start>=0;start--){
            if(s[start]==')'){
                count++;
            }
            else count--;

            if(count==0){
                ans= max(ans, end-start+1);
            }
            if(count<0){
                end= start-1;
                count=0;
            }
        }
        return ans;
    }
    int longestValidParentheses(string s) {
        return max({front(s), back(s),0});
    }
};