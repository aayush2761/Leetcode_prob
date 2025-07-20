class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp;
        for(auto &it : s1)mp[it]++;
        int size= s1.size();
        map<char,int>temp;
        int i=0,j=0;
        while(i<s2.size()){
            temp[s2[i]]++;
            if(temp==mp) return 1;
            if(i-j+1==size){
                temp[s2[j]]--;
                if(temp[s2[j]]==0) temp.erase(s2[j]);
                j++;
            }
            i++;
        }
        return 0;
    }
};