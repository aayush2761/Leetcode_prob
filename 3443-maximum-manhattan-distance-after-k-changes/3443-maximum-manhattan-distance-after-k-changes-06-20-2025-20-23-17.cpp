class Solution {
public:
    int count(string &s){
        int answer=0;
        int x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='N')y++;
            else if(s[i]=='S')y--;
            else if(s[i]=='W')x--;
            else x++;
            answer= max(answer, abs(x)+abs(y));
        }
        return answer;
    }
    int maxDistance(string s, int k) {
        int answer=0;
        string t=s;
        int x=k;
        for(int i=0;i<s.size();i++){
            if((s[i]=='E'|| s[i]=='S')&& k>0){
                t[i]='W';
                k--;
            }
        }
        answer = max(answer, count(t));
        t=s;
        k=x;
        for(int i=0;i<s.size();i++){
            if((s[i]=='N'|| s[i]=='W')&& k>0){
                t[i]='E';
                k--;
            }
        }
        answer = max(answer, count(t));
        t=s;
        k=x;
        for(int i=0;i<s.size();i++){
            if((s[i]=='W'|| s[i]=='S')&& k>0){
                t[i]='E';
                k--;
            }
        }
          answer = max(answer, count(t));
        t=s;
        k=x;
        for(int i=0;i<s.size();i++){
            if((s[i]=='N'|| s[i]=='E')&& k>0){
                t[i]='S';
                k--;
            }
        }
          answer = max(answer, count(t));
        return answer;


    }
};