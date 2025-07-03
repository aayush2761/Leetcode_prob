class Solution {
public:
    char kthCharacter(int k) {
         string res="a";
         while(k>res.size()){
            // adding 
            string temp="";
            for(auto i : res){
                 char c = (i - 'a' + 1) % 26 + 'a'; 
                temp.push_back(c);
            }
            res+=temp;
            
         }
         return res[k-1];
    }
};