class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefMax(n);
        vector<int>suffMax(n);
        // prefix 
        prefMax[0]= height[0];
        for(int i=1;i<n;i++){
            prefMax[i]= max(height[i],prefMax[i-1]);
        }
        // O(n)
        //SuffixMax 
         suffMax[n-1]= height[n-1];
        for(int i=n-2;i>=0;i--){
            suffMax[i]= max(height[i],suffMax[i+1]);
        }
        // O(n)
        int total=0;
        for(int i=0;i<n;i++){
            int leftMax= prefMax[i] ;
            int rightMax= suffMax[i];
            if(height[i]<leftMax && height[i]<rightMax){
                total+= min(leftMax,rightMax)-height[i];
            }
        }
        return total;
    }
};