class Solution {
public:
    bool isValid(string s){
        if(s.size()==0) return 0;
        for(auto &it : s){
            if((it>='a' && it<= 'z') || (it>='A' && it<= 'Z') || (it>='0' && it<= '9') ||(it=='_') ) continue;
            else return 0;
        }
        return 1;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string, vector<string>>mp;

        // vector<string> electronics, grocery, pharmacy, restaurant;
        for(int i=0;i<code.size();i++){
            if(!isValid(code[i])) continue;
            if(businessLine[i]=="invalid") continue;
            if(isActive[i]) mp[businessLine[i]].push_back(code[i]);
        }
        for(auto &it : mp){
            cout<<it.first<<endl;
            for(auto &j: it.second) cout<<j<<" ";
            cout<<endl;
        }

        // order 
        vector<string>result;
        for(auto &it : mp){
            vector<string>temp=it.second;
            if(temp.size()==0) continue;
            sort(temp.begin(), temp.end());
            for(auto &j:temp) result.push_back(j);
        }
        return result; 

    }
};