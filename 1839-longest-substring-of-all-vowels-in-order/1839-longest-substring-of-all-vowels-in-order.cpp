class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<int>value;
        string chars="";
        int i=0;
        int n = word.size();
        while(i<word.size()){
            int temp=1;
            while(i+1<word.size() && word[i]==word[i+1]){
                temp++;
                i++;
            }
            value.push_back(temp);
            chars.push_back(word[i]);
            i++;
        }
        // if(word[n-1]==word[n-2]){
        //     value[value.size()-1]++;
        // }
        // else{
        //     chars.push_back(word[n-1]);
        //     value.push_back(1);
        // }
        // fixed size window of aeiou
        int res=0;
        string key= "aeiou";
        for(int i=0;i<(int)chars.size()-4;i++){
            if(chars.substr(i,5)==key){
                int temp=value[i]+value[i+1]+value[i+2]+value[i+3]+value[i+4];
                res=max(temp,res);
            }
        }
        return res;

    }
};