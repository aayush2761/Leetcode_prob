class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i=0;i<25;i++){
            mp[order[i]]=i;
        }
        // checking each word 
        int prev=-1;
        for(int i=1;i<words.size();i++){
            int j = 0;
            while(j < words[i-1].size() && j < words[i].size()){
                if(words[i-1][j] != words[i][j]){
                    if(mp[words[i-1][j]] > mp[words[i][j]]) return false;
                    break;
                }
                j++;
            }
            if(j == words[i].size() && words[i-1].size() > words[i].size())
                return false;
        }
        return true;
    }
};