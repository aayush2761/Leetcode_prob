class Solution {
public:
      bool check ( unordered_map<char,int>&mpfirst ,unordered_map<char,int>&mpall ){
        // we have to check str2 is same as for str1 or not 
       
        // check 
        for(auto i : mpfirst){
            if(mpall[i.first]!= i.second) return false;
        }
        return true;

    }
    vector<int> findAnagrams(string s2, string s1) {
        vector<int>res;
         int i=0,j=0;
        int s= s1.size();
        unordered_map<char,int>mpfirst;
        for(auto i : s1) mpfirst[i]++;
        unordered_map<char,int>mpall;
        while(i<s2.size()){
            mpall[s2[i]]++;
            if(i-j+1==s){
                if(check(mpfirst, mpall)) res.push_back(j);
                mpall[s2[j]]--;
                j++;
            }
            i++;
        }
        return res;
    }
};