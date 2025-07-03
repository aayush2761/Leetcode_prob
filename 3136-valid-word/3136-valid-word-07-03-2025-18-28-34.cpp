class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n<3) return 0;
        int vowel=0,consonen=0,num=0;
        set<char>st{'a','e','i','o','u','A','E','I','O','U'};
        for(auto it : s){
            int x = it-'0';
            if(x>=0 && x<=9) num++;
            else if (st.count(it))vowel++;
            else if((x>=65 && x<=90)|| (x>=97 || x<= 122))consonen++;
           
           if(it=='@'|| it=='#'|| it=='$') return 0;
        }
        if(vowel>0 && consonen>0 && num>0) return 1;
        return 0;
    }
};