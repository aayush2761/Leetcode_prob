class Solution {
public:
    void recursiveCall(int i,int n , vector<int>&ans){
        //base case
        if(i>n) return ;
        //push i
        ans.push_back(i);
        //recursive function
        for(int j=0;j<10;j++){
            if(10*i+j>n)
                    return ;
                recursiveCall(10*i+j, n, ans);
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<10;i++){
            recursiveCall(i,n,ans);
        }
        return ans;
    }
};