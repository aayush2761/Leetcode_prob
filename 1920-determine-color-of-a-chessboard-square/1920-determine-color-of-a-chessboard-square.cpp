class Solution {
public:
    bool squareIsWhite(string cs) {

        int x = static_cast<char>(cs[1]);
        if((cs[0]=='a')||(cs[0]=='c')||(cs[0]=='e')||(cs[0]=='g')){
            if(x%2==0) return true;
            return false;
        }
        else{
             if(x%2!=0) return true;
            return false;
           }
    

    }
};