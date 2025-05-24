class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
                vector<int>result;
            for(int i=0;i<words.size();i++){
                // if(words[i].find(x)!= string::npos){
                if(count(words[i].begin(),words[i].end(),x)){
                    result.push_back(i);
        }
        }
        return result;

    }
};