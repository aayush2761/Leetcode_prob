class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        vector<long long>res(n,0LL);
        map<int, vector<long long>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto & it : mp){
            if(it.second.size()==1) continue;
            vector<long long>temp= it.second;
            int size= temp.size();
            vector<long long >pref(size,0);
            pref[0]= temp[0];
            for(int i=1;i<size;i++){
                pref[i]= pref[i-1]+ temp[i];
            }
            vector<long long>suff(size,0);
            suff[size-1]= temp[size-1];
            for(int i=size-2;i>=0;i--){
                suff[i]= suff[i+1]+ temp[i];
            }
            //print
            // for(int i=0;i<size;i++)cout<<pref[i]<<" ";
            // cout<<endl;
            // for(int i=0;i<size;i++)cout<<suff[i]<<" ";
            // cout<<endl;
            // fill the res vector
            for(long long i=0;i<size;i++){
                res[temp[i]]= (long long )( ((i+1)*temp[i])- pref[i]) + (long long )(suff[i]- ((size-i)*temp[i]));
            }
        }
        return res;
    }
};