class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(auto i : nums1) mp1[i]++;
        for(auto i : nums2) mp2[i]++;
        vector<int>res;
        // consider always nums2 is smaller 
        for(auto i : mp2){
            int a = i.first;
            int b= i.second;
            if(mp1.find(a)!=mp1.end()){
                int temp= min(b,mp1[a]);
                while(temp--) res.push_back(a);
            }
        }
        return res;
    }
};