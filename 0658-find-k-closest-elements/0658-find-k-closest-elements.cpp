class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // brute ------ sbse k minus krke then sort thre arrayt and return 
        // obtimise using max heap to remove far distances elements 
           priority_queue<pair<int,int>>maxH; 
           // pair of heap (arr[i] , arr[i]-x)
           int i=0;
           while(i<arr.size()){
            maxH.push( {abs(arr[i]-x), arr[i]});
            if(maxH.size()>k) maxH.pop();
            i++;

           }
           vector<int>res;
           while(k--){
            res.push_back(maxH.top().second);
            maxH.pop();
           }
           sort(res.begin(),res.end());
           return res;
    }
};