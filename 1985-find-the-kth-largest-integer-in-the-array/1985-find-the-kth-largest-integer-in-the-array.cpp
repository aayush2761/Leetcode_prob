class Solution {
public:
   
    string kthLargestNumber(vector<string>& nums, int k) {
        auto  cmp=[](string &a ,string &b ){
     if(a.size() == b.size()) {
                return a > b;
            }
            return a.size() > b.size();
   };
        priority_queue<string,vector<string>,decltype(cmp)>pq;
        for(auto i :  nums){
            // double t = get(i);
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};