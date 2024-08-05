class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
              unordered_map<string,int>mp;
            //   priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>pq;
            for(auto i : arr) mp[i]++;
            int c=0;
            for(int i=0;i<arr.size();i++){
                if(mp[arr[i]]==1){
                   c++;
                    if(c==k) return arr[i];
                }
            }
            return "";



    }
};