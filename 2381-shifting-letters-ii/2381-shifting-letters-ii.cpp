class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n+1,0);
        // queries 
        for(int i=0;i<shifts.size();i++){
            int left = shifts[i][0];
            int right = shifts[i][1];
            int dir = shifts[i][2];
            if(dir==0){
                diff[left]+=(-1);
                diff[right+1]+=1;
            }
            else{
                diff[left]+=(1);
                diff[right+1]+=-1;
            }
        }
        // queries done 
        for(int i=1;i<=n;i++){
            diff[i]+=diff[i-1];
        }
        // result 
       for (int i = 0; i < n; i++) {
        char cc = s[i];
         int ci = (cc - 'a' + diff[i]) % 26; 
        if (ci < 0) ci += 26;              
        char res = 'a' + ci;               
        s[i] = res;                       
        }


        return s;
    }
};