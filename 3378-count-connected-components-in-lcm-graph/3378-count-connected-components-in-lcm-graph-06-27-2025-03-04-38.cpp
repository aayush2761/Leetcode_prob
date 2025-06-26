class Solution {
public:
//    vector<int> parent = vector<int>(100001), rank = vector<int>(100001, 0);
    int find(int u, vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]= find(parent[u], parent);
    }
    void setUnion(int u, int v,vector<int>&parent,vector<int>&rank){
        int pu= find(u,parent);
        int pv= find(v,parent);

        if(pu==pv) return;
        // rank condtions 
        if(rank[pu]>rank[pv]){
            parent[pv]= pu;
            
        }
        else  if(rank[pu]<rank[pv]){
            parent[pu]= pv;
        }
        else{
            parent[pv]= pu;
            rank[pu]++;
        }
    }
    int countComponents(vector<int>& nums, int threshold) {
       int n= nums.size();
       vector<int> parent(threshold + 1), rank(threshold + 1, 0);
        for (int i = 0; i <= threshold; i++) parent[i] = i;
       for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= threshold) {
                // iterating on all multiple of nums[i]
                for(int j=nums[i]; j <= threshold; j+=nums[i]) {
                    // joining nums[i] with its multiple
                    setUnion(nums[i], j,parent,rank);
                }
            }
        }
       int ans = 0;
       set<int>res;
        for(int num : nums) {
            if(num > threshold) ans++;
            else res.insert(find(num,parent));
        }
        return ans + res.size();

    }
};