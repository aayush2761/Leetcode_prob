class Solution {
public:
    bool palindrome(string &s){
        int i=0,j= s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    void solve(string s , vector<vector<string>>&res,int index,vector<string>temp){
        if(index == s.size()) {
            if(temp.size()>0)res.push_back(temp);
            return;
        }
        for(int i= index;i<s.size();i++){
            string t= s.substr(index, i-index+1); // this will decide the size of the string s 
            if(palindrome(t)){
                temp.push_back(t);
                solve(s,res,i+1, temp);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        // variable are size and index
        vector<string>temp; 
        solve(s, res, 0,temp);
        return res;
    }
}; 