class Solution {
public:
    bool helper(int mid, vector<int>&  piles, int h){
        int count=0;
        int i=0;
        int n=piles.size();
        while(i<n){
            count += (piles[i] + mid - 1) / mid; // Use ceiling logic
            if (count > h) return false;
            i++;

        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(), piles.end());
        int res=0;
        while(low<=high){
            int mid = low + (high-low) /2;
            if(helper(mid,piles,h)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};