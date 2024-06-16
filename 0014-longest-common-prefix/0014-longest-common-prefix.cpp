class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // index, pair(char,freq)
        int n=strs.size();
        if(n==1) return strs[0];
        // get length
        int maxi=INT_MAX;
        for(int i=0;i<n;i++){
         if(strs[i].size()<=maxi) maxi=strs[i].size();
       }
       for(int i=0;i<n;i++){
         if(strs[i]=="") return strs[i];
       }
        string res="";
        for(int i=0;i<maxi;i++ ){
            char temp= strs[0][i];
            int j=1;
            while(j<n){
                if(strs[j][i] != temp){
                    return res;
                }
                j++;
            }
            if(j==n) res+=temp;
        }
        return res;
    }
};