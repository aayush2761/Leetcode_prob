#define ll long long int
class Solution {
public:
    // Rabin karp 
    int getAns(string & s , int len){
        int ans=0,n=s.size();
        ll hash =0, powBaseLen=1, mod= 1e9+7;
        unordered_map<ll, vector<int>> store;
        for(int i=0;i<len;i++){
           hash = ((hash*26)%mod + s[i]-'a'+1)%mod;
            if(i != 0) powBaseLen = (powBaseLen*26)%mod;
        }
        store[hash].push_back(0);

        for(int i=1;i<=(n-len);i++){
           ll diff = ((s[i-1]-'a'+1)*powBaseLen)%mod;
            hash = (((hash - diff + mod)*26)%mod + s[i+len-1]-'a'+1)%mod;

            if(store.find(hash) != store.end()){
                string s1 = s.substr(store[hash][0], len);
                string s2 = s.substr(i, len);
                if(s1 == s2) return i;
            }
            store[hash].push_back(i);
        }

        return -1;
    }
    string longestDupSubstring(string s) {
        // Rabin Karp Method --------------------->>>>>>>>
        int n = s.size();
        int i=0,j=n-1;
        string ans="";
        while(i<=j){
            int mid= (i+ j)/2;
            int a = getAns(s, mid+1);
            if(a!=-1){
                ans=s.substr(a,mid+1);
                i=mid+1;
            }
            else{
                j=mid-1;

            }

        }
        return ans;
        
    }
};



// --------------------------> BASIC HASHING    <-----------------------------//


// class Solution {
// public:
//     string longestDupSubstring(string s) {
//         int res=0;
//         string ans;
//         unordered_map<string,int>mp;
         
//         for(int j=0;j<s.size();j++){
//             string temp="";
//             for(int i=j;i<s.size();i++){
//            temp+=s[i];
//            mp[temp]++;
//         //    cout<<temp<<endl;
//            if(mp[temp]>1){
//             if(ans.size()<temp.size())ans=temp;
//             // res=temp.size();
//            }
           

//         }
//         }
//         return ans;
//     }
// };