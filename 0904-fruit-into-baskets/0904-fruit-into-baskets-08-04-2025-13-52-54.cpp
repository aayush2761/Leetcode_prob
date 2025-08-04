class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0,j=0;
        int res=0;
         while(i<fruits.size()){
            mp[fruits[i]]++;
            if(mp.size()<3) res= max(res, i-j+1);
            else{
                mp[fruits[j]]--;
                 if(mp[fruits[j]]==0) mp.erase(fruits[j]);
                 j++;
            }
            i++;
         }
         return res;
    }
};