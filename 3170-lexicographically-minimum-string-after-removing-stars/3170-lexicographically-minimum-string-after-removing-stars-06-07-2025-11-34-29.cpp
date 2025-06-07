struct comp{
    bool operator()(pair<char,int>&a, pair<char,int>&b){
            if(a.first!=b.first) return a.first>b.first;
            return  a.second<b.second;
    }
};
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        if(s[0]=='*') return "";
        // pair<char,int>
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        vector<bool>takeElements(n,true);
        for(int i=0;i<n;i++){
            if(s[i]!='*') pq.push({s[i],i});
            else {
                auto it = pq.top();
                pq.pop();
                takeElements[it.second]=false;
                takeElements[i]=false;

            }
        }
        string res="";
        for(int i=0;i<n;i++){
            if(takeElements[i]) res.push_back(s[i]);
        }
        return res;

    }
};