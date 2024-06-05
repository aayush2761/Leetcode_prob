class Solution {
public:
    int minDistance(string word1, string word2) {
        int maximum = word1.size()+ word2.size();
      int index1= word1.size();
        int index2= word2.size();
        vector<int>prev(index2+1,0), curr(index2+1,0);
        // base case 
        // for(int i =0;i<=index1;i++) dp[i][0]=0;
        for(int i =0;i<=index2;i++) prev[i]=0;

        // changeing parameret 
        for(int i=1;i<=index1;i++){
            for(int j=1;j<=index2;j++){
                // copy the recursioin
                 if(word1[i-1]== word2[j-1]){
                     curr[j]= 1+ prev[j-1];
            
                 }
               // unmatch case
            else curr[j]= 0+ max(curr[j-1] ,  prev[j]);
            }
            prev=curr;
        
        }
       int commonSubSequence=  prev[index2];
       return maximum- commonSubSequence*2;
    }
};