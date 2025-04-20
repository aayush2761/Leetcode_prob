class Solution {
public:
    unordered_map<int,int> m;
    int numRabbits(vector<int>& answers) {
        m.clear();
        if(answers.empty()) return 0;
        int res=0;
        for(int a:answers){
            if(a==0) res++;
            else{
                if(m[a]==0) res+=a+1;
                m[a]++;
                if(m[a]==a+1) m[a]=0;
            }           
        }
        return res;
    }
};