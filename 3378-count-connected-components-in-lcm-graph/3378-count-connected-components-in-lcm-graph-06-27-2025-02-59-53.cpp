// class Solution {
// public:
// //    vector<int> parent = vector<int>(100001), rank = vector<int>(100001, 0);
//     int find(int u, map<int,int>&parent){
//         if(parent[u]==u) return u;
//         return parent[u]= find(parent[u], parent);
//     }
//     void setUnion(int u, int v,map<int,int>&parent,map<int,int>&rank){
//         int pu= find(u,parent);
//         int pv= find(v,parent);

//         if(pu==pv) return;
//         // rank condtions 
//         if(rank[pu]>rank[pv]){
//             parent[pv]= pu;
            
//         }
//         else  if(rank[pu]<rank[pv]){
//             parent[pu]= pv;
//         }
//         else{
//             parent[pv]= pu;
//             rank[pu]++;
//         }
//     }
//     int countComponents(vector<int>& nums, int threshold) {
//        int n= nums.size();
//        int maxi = max(*max_element(nums.begin(), nums.end()), threshold);
//         map<int,int>parent,rank;
//         for(int  i=0;i<=maxi;i++){
//             parent[i]=i;
//             rank[i]=0;
//         }
//        for(int i=0; i<nums.size(); i++) {
//             if(nums[i] <= threshold) {
//                 // iterating on all multiple of nums[i]
//                 for(int j=nums[i]; j <= threshold; j+=nums[i]) {
//                     // joining nums[i] with its multiple
//                     setUnion(nums[i], j,parent,rank);
//                 }
//             }
//         }
//         set<int>res;
//     //   for(int i=0;i<maxi;i++) cout<<parent[i]<<endl;
//         for (int num : nums) res.insert(find(num,parent));
//         return res.size();
//     }
// };


class Solution {
    class DSU {
        vector<int> parent;
        public:
        DSU(int n) : parent(n+1, -1) {}
        int findParent(int x) {
            if(parent[x] == -1) return x;
            return parent[x] = findParent(parent[x]);
        }
        bool join(int x, int y) {
            int X = findParent(x);
            int Y = findParent(y);
            if(X==Y) return false;
            parent[X] = Y;
            return true;
        }
    };
public:
    int countComponents(vector<int>& nums, int threshold) {
        DSU dsu(threshold);
        int n = nums.size();
        int ans = 0;

        // Worst case Time Complexity of this loop is th/1 + th/2 + th/3 + th/4 + .. + th/k
        // Here th is threshold and k is max value of nums such that k <= threshold
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= threshold) {
                // iterating on all multiple of nums[i]
                for(int j=nums[i]; j <= threshold; j+=nums[i]) {
                    // joining nums[i] with its multiple
                    dsu.join(nums[i], j);
                }
            }
        }

        set<int> st; // contains the parents of each nums[i]
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > threshold) ans++; // this number itself is a component
            else st.insert(dsu.findParent(nums[i]));
        }

        ans += st.size(); // number of unique parents = number of components
        // Please upvote if liked else downvote if didn't like the solution
        return ans;
    }
};