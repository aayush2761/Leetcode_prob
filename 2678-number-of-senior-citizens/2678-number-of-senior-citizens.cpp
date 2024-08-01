class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(int i=0;i<details.size();i++){
            // if(((details[11] - '0') * 10 + (details[12] - '0')) > 60 ) res++;
            if (((details[i][11] - '0') * 10 + (details[i][12] - '0')) > 60) res++;

        }
        return res;
    }
};