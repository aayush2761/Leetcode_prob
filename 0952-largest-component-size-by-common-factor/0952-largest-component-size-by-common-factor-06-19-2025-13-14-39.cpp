class Solution {
public:
    vector<int>parent , rank;
    int find(int u, vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]= find(parent[u], parent);
    }
    void unionSet(int u , int v, vector<int>&parent,vector<int>&rank){
        int pu = find(u, parent);
        int pv = find(v, parent);
        if(pu==pv) return;
        // rank conditions 
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else  if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int size = *max_element(nums.begin(), nums.end());
        parent.resize(size+1);
        rank.resize(size+1,0);
        for(int i=0;i<=size;i++) parent [i]=i;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==j) continue;
        //         else {
        //             int pu = find(nums[i], parent);
        //             int pv = find(nums[j], parent);
        //             if(pu==pv) continue;
        //             else if(__gcd(nums[i],nums[j])>1){
        //                 unionSet(pu,pv, parent, rank);
        //             }
        //         }
        //     }
        // }
        for(int num : nums) {
            for(int factor = 2; factor * factor <= num; factor++) {
                if(num % factor == 0) {
                    unionSet(num, factor, parent, rank);
                    unionSet(num, num / factor, parent, rank);
                }
            }
        }
        int answer= INT_MIN;
        unordered_map<int,int>mp;
        for(int num : nums) {
            int root = find(num, parent);
            mp[root]++;
        }
        for(auto & it : mp) answer= max(answer, it.second);
        return answer; 
    }
};