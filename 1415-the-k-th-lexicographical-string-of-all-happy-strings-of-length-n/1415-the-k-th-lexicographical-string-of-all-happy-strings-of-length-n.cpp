class Solution {
public:
    string getHappyString(int n, int k) {
        string result = "";
        if(k > 3*(1<<(n-1))) return result; // if k is out of range, then return Empty string
        h(n, k, -1, result); // else start building the string
        return result;
    }
    void h(int n, int k, int lastChar, string&result){
        if(n==0) return; // base case

        for(int i=0;i<3;i++){ // explore for options lexicographically
            if(i==lastChar) continue; // consecutive chars can't be same so skip it
            else{
                if(1<<(n-1) < k) k-=(1<<(n-1));
                else{
                    result.push_back(char(i + 'a'));
                    h(n-1, k, i, result);
                    return;
                }
            }
        }
    }
};