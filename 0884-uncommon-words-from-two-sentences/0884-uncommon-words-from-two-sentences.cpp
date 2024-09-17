class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp;
        int j=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                string temp = s1.substr(j, i - j);
                mp[temp]++;
                j=i+1;
            }
        }
        // last
         string temp = s1.substr(j);
         mp[temp]++;

         // second string
         vector<string>res;
         j=0;
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                string temp = s1.substr(j, i - j);
                if (mp.find(temp) == mp.end()) {
                    mp[temp]++; 
                } else {
                    mp[temp]--;  
                }
                j=i+1;
            }
        }
        // last
         temp = s2.substr(j);
         if(mp.find(temp)==mp.end()){
                    mp[temp]++;
                }
                else mp[temp]--;

        // store in res
        for(auto i : mp) {
            if(i.second==1) res.push_back(i.first);
            // jo common hai unka count 0 hai but wo remove nhi hua hai 
            // isliye we are using this condition of i.second ==1
        }
        return res;
    }
};