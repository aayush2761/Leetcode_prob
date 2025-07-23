class Solution {
public:
    // ab stack 
    int abScore(string s, vector<int>&vis, int x){
        int answer=0;
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if( s[i]=='a' && vis[i]==-1) {
                // vis[i] =1;
                st.push({s[i],i});
            }
            else if(s[i]!= 'a' && s[i]!='b'){
                while(!st.empty())st.pop();
            }
            else if(s[i]=='b' && !st.empty() && vis[i]==-1){
                vis[i]=1;
                auto it=  st.top();
                vis[it.second]=1;
                st.pop();
                answer+=x;
            }
        }
        return answer;
    }
    // ba stack;
    int baScore(string s, vector<int>&vis, int x){
        int answer=0;
          stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if( s[i]=='b' && vis[i]==-1) {
                // vis[i] =1;
                 st.push({s[i],i});
            }
            else if(s[i]!= 'a' && s[i]!='b'){
                while(!st.empty())st.pop();
            }
            else if(s[i]=='a' && !st.empty() && vis[i]==-1){
                vis[i]=1;
                 auto it=  st.top();
                vis[it.second]=1;
                st.pop();
                answer+=x;
            }
        }
        return answer;
    }
    int maximumGain(string s, int x, int y) {
            int n = s.size();
            vector<int>vis(n,-1);
            int res=0;
            if(x>=y){
                res= abScore(s,vis,x);
                res+= baScore(s,vis,y);

            }
            else {
                res= baScore(s,vis,y);
                res+= abScore(s,vis,x);
            }
            return res;
    }
};