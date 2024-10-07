class Solution {
public:
    bool check(string & s , bool & flag){
        cout<<s<<" "<<endl;
        for(int i=1;i<s.size();i++){
            if((s[i]=='B' && s[i-1]=='A') || (s[i]=='D' && s[i-1]=='C')){
                string temp= s.substr(0,i-1) + s.substr(i+1);
                s=temp;
                
                flag=true;
                return true;
            }
        }
        flag=false;
        return false;
    }
    int minLength(string s) {
        bool flag = true;
        while(flag==true){
            if(check(s,flag)){
                cout<<s<<endl;
                check(s,flag);
            }
        }
        return s.size();
    }
};