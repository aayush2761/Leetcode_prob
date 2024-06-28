class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // custom xomparator 
        auto compare = [&](const vector<int>& a ,const vector<int>& b  ){
            return a[0]+ a[1] > b[0] + b[1];
        };
        
         priority_queue<vector<int>, vector<vector<int>> , decltype(compare)>pq(compare);
         vector<vector<int>>res;

         // push first k eligible pairs 
         for(int i=0;i<nums1.size() && i<k ;i++){
            pq.push({nums1[i] , nums2[0] , 0});
         }

         while(k-- && !pq.empty()){
            vector<int>curr = pq.top();
            pq.pop();
            res.push_back({curr[0] , curr[1]});
            // check for the index of the top element
            if(curr[2]==nums2.size()-1) continue;

            // increase the index and push it into min heap
            pq.push({curr[0] , nums2[curr[2]+1] , curr[2]+1});
         }
         return res;
    }
};