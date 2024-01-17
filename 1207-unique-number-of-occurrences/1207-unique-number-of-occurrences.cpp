class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       int k=1000;
       vector<int>array(2*k+1);
       for(int el : arr){
           array[el+k]++;
       }
       sort(array.begin(),array.end());
       for(int i=0;i<2*k;i++){
           if(array[i]!=0 && array[i]==array[i+1]) return false;
       }
       return true;
    }
};