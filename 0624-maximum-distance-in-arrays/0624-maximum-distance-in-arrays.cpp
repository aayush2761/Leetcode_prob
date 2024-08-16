class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // int mini=INT_MAX;
        // int maxi=INT_MIN;
        int n = arrays.size();
        // for(int i=0;i<n;i++){
        //     mini=min(mini,arrays[i][0] );
        //     int m = arrays[i].size();
        //     maxi=max(maxi,arrays[i][m-1] );
        // }
        // return maxi-mini;
        // vector<int>mini;
        // vector<int>maxi;
        // for(int i=0;i<n;i++){
        //      int m = arrays[i].size();
        //      mini.push_back(arrays[i][0]);
        //      maxi.push_back(arrays[i][m-1]);
        // }
        // sort(mini.begin(),mini.end());
        // sort(maxi.begin(),maxi.end());
        // return maxi[maxi.size()-1]-mini[0];
        // sort(arrays.begin(),arrays.end());
        // int a= abs(arrays[0][0]-arrays[n-1][arrays[n-1].size()-1]);
        // int b= abs(arrays[0][arrays[0].size()-1]-arrays[n-1][0]);
        // // int b = abs()
        // return max(a,b);
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            max_distance = max(max_distance, abs(arrays[i].back() - smallest));
            max_distance = max(max_distance, abs(biggest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }

        return max_distance;
    }
};


// two diff integers from two diff array 
