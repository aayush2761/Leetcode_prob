class Solution {
public:
     void calc(int start,  string& s, vector<string>& tmp, vector<vector<string>>& ans){
          if (start == s.size()) {
            ans.push_back(tmp);
            return;
          }
          for (int i = 1; start + i <= s.size(); ++i) {
            tmp.push_back(s.substr(start, i));
            calc(start + i, s, tmp, ans);
            tmp.pop_back();
          }
    }
    bool check(int n){
        long square=n*n;
        string x=to_string(square);       
          vector<vector<string>> res;
         vector<string> tmp;
        calc(0, x, tmp, res);
        for(auto i:res){
            int s=0;
            for(auto j:i)
                s+=stoi(j);
            if(s==n) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int res=1;
        for(int i=2;i<=n;i++){
            if(check(i)) {
                res+=(i*i);
                cout<<i<<endl;
            }
        }
        return res;
    }
};