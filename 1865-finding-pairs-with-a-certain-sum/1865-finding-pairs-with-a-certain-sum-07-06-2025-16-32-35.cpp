class FindSumPairs {
public:
    unordered_map<int,int>mp1, mp2;
    vector<int>temp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto & it : nums1)mp1[it]++;
        for(auto & it : nums2)mp2[it]++;
        temp=nums2;
    }
    
    void add(int index, int val) {
        int v=temp[index];
       temp[index]+=val;
       int x= temp[index];
       mp2[v]--;
       if(mp2[v]==0)mp2.erase(v);
       mp2[x]++;
    }
    
    int count(int tot) {
        int res=0;
        for(auto & it : mp1){
            if(mp2.find(tot-it.first)!= mp2.end()){
                res+= it.second* mp2[tot-it.first];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */