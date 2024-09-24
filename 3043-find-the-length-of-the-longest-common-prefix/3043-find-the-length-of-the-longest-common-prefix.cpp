class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        // flooding
        for(int i=0;i<arr1.size();i++){
            string t= to_string(arr1[i]);
            string temp="";
            for(auto i : t ){
                temp+=i;
                mp[temp]++;
            }
        }
        // excavatiing
        int res=0;
         for(int i=0;i<arr2.size();i++){
            string t= to_string(arr2[i]);
            string temp="";
            for(auto i : t ){
                temp+=i;
                if(mp.find(temp)!=mp.end()){
                    res=max(res,(int)temp.size());
                }
            }
        }
        return res;


    }
};









       //------------------> BRUTE FORCE <-----------------------------//



// class Solution {
// public:
//     int check(int  p , int  q ){
//         string a =to_string(p);
//         string b = to_string(q);
//         int len= min(a.size(),b.size());
//         int res=0;
//         for(int i=0;i<len;i++){
//             if(a[i]==b[i]) res++;
//             else break;
//         }
//         return res;
//     }
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int ans=INT_MIN;
//         for(int i=0;i<arr1.size();i++){
//             for(int j=0;j<arr2.size();j++){
//                 ans=max(ans,check(arr1[i],arr2[j]));
//             }
//         }
//         return ans;
//     }
// };