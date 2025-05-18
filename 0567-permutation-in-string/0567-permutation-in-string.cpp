class Solution {
public:
    bool check(unordered_map<char,int>&mp1, unordered_map<char,int>&mp2){
        for(auto it: mp1){
            if(mp2.find(it.first)==mp2.end())return 0;
            if(it.second!= mp2[it.first])return 0;
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int n= s1.size();
        unordered_map<char,int>mp1, mp2;
        for(auto it : s1){
            mp1[it]++;
        }
        int i=0,j=0;
        while(i<s2.size()){
            mp2[s2[i]]++;
            if(i-j+1==n){
                if(check(mp1,mp2))return true;
                else{
                    mp2[s2[j]]--;
                    if(mp2[s2[j]]==0)mp2.erase(s2[j]);
                    j++;
                }
            }
            i++;
        }
        
    return 0;
    }
};