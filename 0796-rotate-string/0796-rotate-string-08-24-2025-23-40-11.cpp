class Solution {
public:
    void zAlgo(string s, vector<int>&z){
        int l=0,r=0;
        for(int i=1;i<s.size();i++){
            if(r>i)z[i]= min(r-i, z[i-l]);
            while(i+z[i]<s.size() && s[z[i]]==s[z[i] + i]) z[i]++;
            if(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }
    }
    bool rotateString(string s, string goal) {
        if(s.size()!= goal.size()) return 0;
        string temp= s + '$'+ goal + goal;
        int n = temp.size();
        vector<int>z(n,0);
        zAlgo(temp,z);
        for(auto &it : z) {
            if(it==goal.size()) return 1;
        }
        return 0;
    }
};