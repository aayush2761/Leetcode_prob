class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;
        for(auto &i : logs){
            mp[i[0]]++;
            mp[i[1]+1]--;
        }
        int sum = 0;
        int maxi = INT_MIN;
        int ans;
        for(auto i : mp){
            sum+=i.second;
           if(sum > maxi)
            {
                maxi = sum;
                ans = i.first;
            }
        }
        return ans;
    }
};