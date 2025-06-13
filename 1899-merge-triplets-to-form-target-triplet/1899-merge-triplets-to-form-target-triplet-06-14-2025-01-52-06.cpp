class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
       
        int n= target.size();
        vector<int>visited(n,false);
        for(int i=0;i<triplets.size();i++){
            int count =0;
            if(triplets[i][0]==target[0])visited[0]=true;
            if(triplets[i][1]==target[1])visited[1]=true;
            if(triplets[i][2]==target[2])visited[2]=true;
            if(visited[0] && visited[1] && visited[2] ) return true;
        }
        return false;
    }
};