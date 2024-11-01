class Solution {
public:
  string makeFancyString(string s) {
    string ans;
    for(int i = 0; i < s.size(); i++) {
      ans += s[i];
      if(ans.size() > 2 && ans.back() == ans[ans.size() - 2] && ans[ans.size() - 2] == ans[ans.size() - 3]) {
        ans.pop_back();
      }
    }
    return ans;
  }
};
