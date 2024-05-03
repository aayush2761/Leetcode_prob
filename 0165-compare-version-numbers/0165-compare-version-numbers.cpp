class Solution {
public:

    int compareVersion(string version1, string version2) {
        vector<int>v1 ;
         vector<int>v2 ;
         istringstream iss1(version1),iss2(version2);
         string token;

         while(getline(iss1, token, '.')) v1.push_back(stoi(token));
         while(getline(iss2, token, '.')) v2.push_back(stoi(token));

         int value1,value2;
         for(int i=0;i<max(v1.size(),v2.size());i++){
            value1= i< v1.size() ? v1[i] : 0;
             value2= i< v2.size() ? v2[i] : 0;
             if(value1<value2) return -1;
             else if (value1>value2) return 1;

         }
         return 0;

    }


    
};