class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        	    // Code here
		      int index1= str1.size();
        int index2= str2.size();
        vector<vector<int>>dp(index1+1 , vector<int>(index2+1, 0));
        // base case 
        for(int i =0;i<=index1;i++) dp[i][0]=0;
        for(int i =0;i<=index2;i++) dp[0][i]=0;

        // changeing parameret 
        for(int i=1;i<=index1;i++){
            for(int j=1;j<=index2;j++){
                // copy the recursioin
                 if(str1[i-1]== str2[j-1]){
                     dp[i][j]= 1+ dp[i-1][j-1];
            
                 }
                // unmatch case
            else dp[i][j]= 0+ max(dp[i][j-1] ,  dp[i-1][j]);
            }
        }

        //___________------------PRITNING SEQUNECE ____________---------------//



        // return dp[index1][index2];
       
       int len = dp[index1][index2];
  int i = index1;
  int j = index2;

  int index = len - 1;
  string ans = "";

  while (i > 0 && j > 0) {
    if (str1[i - 1] == str2[j - 1]) {
      ans += str1[i-1];
      index--;
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        ans += str1[i-1];
        i--;
    } else {
        ans += str2[j-1];
        j--;
    }
  }
        
        // return ans;
        // check if it end up leaving somecharacter of either of the string
        // 1 based indexing

       while(i>0){
      ans += str1[i-1];
      i--;
  }
  while(j>0){
      ans += str2[j-1];
      j--;
  }

  reverse(ans.begin(),ans.end());
  
  return ans;
}
  
};