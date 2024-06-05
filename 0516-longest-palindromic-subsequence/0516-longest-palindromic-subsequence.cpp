class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1= s;
        // revese the stringg s and treat it as s2 and find thr LCSubstring
        reverse(s.begin(), s.end());
        string text2= s;
        int index2= text2.size();
        vector<int>prev(index2+1,0), curr(index2+1,0);
        // base case 
        // for(int i =0;i<=index1;i++) dp[i][0]=0;
        for(int i =0;i<=index2;i++) prev[i]=0;

        // changeing parameret 
        for(int i=1;i<=index2;i++){
            for(int j=1;j<=index2;j++){
                // copy the recursioin
                 if(text1[i-1]== text2[j-1]){
                     curr[j]= 1+ prev[j-1];
            
                 }
               // unmatch case
            else curr[j]= 0+ max(curr[j-1] ,  prev[j]);
            }
            prev=curr;
        
        }
       return prev[index2];
    }
};