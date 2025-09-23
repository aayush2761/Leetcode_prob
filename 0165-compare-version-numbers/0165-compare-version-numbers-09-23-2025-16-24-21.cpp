class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>v1,v2;
        stringstream ss1(version1), ss2(version2);
        string token1="", token2="";
        while(getline(ss1,token1,'.')) v1.push_back(token1);
        while(getline(ss2,token2,'.')) v2.push_back(token2);
        // check 
        int i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            int x= stoi(v1[i]);
            int y= stoi(v2[j]);
            if(x>y) return 1;
            else if(y>x) return -1;
            else {
                i++;
                j++;
            }
        }
        if(i==v1.size()){
                while(j<v2.size()){
                    int z= stoi(v2[j]);
                    if(z>0) return -1;
                    j++;
                }
        }
        if(j==v2.size()){
                while(i<v1.size()){
                    int z= stoi(v1[i]);
                    if(z>0) return 1;
                    i++;
                }
        }
        return 0;
    }
};