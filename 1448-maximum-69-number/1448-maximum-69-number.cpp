class Solution {
public:
    int maximum69Number (int n) {
        //vector wagera push wush krke dekh lena ek vaari 
        vector<int> v1;
        
        while(n>0){
           v1.push_back(n%10);
           n=n/10;
        }
        reverse(v1.begin(), v1.end());
        int e=v1.size();
        for(int i=0;i<e;i++){
            if(v1[i]==6){
                v1[i]=9;
                break;
            }
        }
        int ans=0;
        for(int i=0;i<e;i++){
            ans=ans*10 + v1[i];

        }
        return ans;
    }
};