class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // return 0;
        sort(skill.begin(),skill.end());
        long long res=0;
        int n = skill.size();
        long long s = skill[0]+skill[n-1];
        int i=0, j=n-1;
        while(i<j){
            if(s!=skill[i]+skill[j]) return -1;
            // cout<<res<<endl;
            res+= (skill[i]*skill[j]);
            i++;
            j--;
        }
        return res;
    }
};


// [1,1,1,2,3,3,3,7,7,8,8,8,9,9]