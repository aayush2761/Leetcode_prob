class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res,s="";
        while(a!=0|| b!=0){
            s=res;
            if(s.size()>=2 && s.substr(s.size()-2)=="aa"){
                res+='b';
                b--;
            }
            else if(s.size()>=2 && s.substr(s.size()-2)=="bb"){
                res+='a';
                a--;
            }
            else if(a>b){
                res+='a';
                a--;
            }
            else{
                res+='b';
                b--;
            }

        }
        return res;
        
    }
};