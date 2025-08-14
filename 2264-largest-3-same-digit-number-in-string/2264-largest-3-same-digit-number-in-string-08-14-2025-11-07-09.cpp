class Solution {
public:
    string largestGoodInteger(string num) {
        int res=0;
        string ans="";
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                string temp = num.substr(i-2,3);
                int x = stoi(temp);
                if(x>=res){
                    res=x;
                    ans=temp;
                }
            }
        }
        // if(ans=="000") return "";
        return ans;
    }
};