class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //sort(arr2.begin(), arr2.end());
        int  n= arr1.size();
       map<int,int>mp;
       for(auto i :  arr1) mp[i]++;
       vector<int>res;
       // code 
       for(int i=0;i<arr2.size();i++){
       // res.push_back(arr2[i]);
        auto it= mp.find(arr2[i]);
        if( it != mp.end()){
            int t = it->second;
            while(t--){
                res.push_back(it->first);
            }
            it->second=0;
        }
       }
       // remaining elemets in ascending order
       for(auto i : mp){
        if( i.second!=0){
            while(i.second--){
                res.push_back(i.first);
            }
        }
       }
       return res;
    }
};