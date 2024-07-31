class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int last = arr[n-1];
        if(last==n) return last+k;
        // vector<int>res;
        int ind=0;
        int i=1;
        while(i<=2000){
            if(ind<n && i==arr[ind]){
                ind++;
                // continue;
            }
            else{
                // res.push_back(i);
                k--;
            }
            if(k==0) return i;
            i++;
        }
        return -1;
    }
};