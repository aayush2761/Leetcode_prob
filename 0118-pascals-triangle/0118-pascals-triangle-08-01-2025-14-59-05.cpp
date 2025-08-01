class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        vector<int>prev(1,1);
        for(int n=2;n<=numRows;n++){
             vector<int>temp(n);
             // fill first and last
             temp[0]= prev[0];
             temp[n-1]= prev[n-2];
             // fill the middle 
             int prevIndex=1;
             int tempIndex=1;
             while(prevIndex<n-1){
                temp[tempIndex]= prev[prevIndex] + prev[prevIndex-1];
                prevIndex++;
                tempIndex++;

             }
             res.push_back(prev);
             prev=temp;
        }
          res.push_back(prev);
          return res;
    }
};