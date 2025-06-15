class Solution {
public:
    string generateTag(string s) {
        stringstream ss(s);
        string word;
        vector<string> result;

        while (ss >> word) {
            result.push_back(word);
        }
        string res="#";
        for(int i=0;i<result.size();i++){
            if(i==0){
                result[i][0] = tolower(result[i][0]);
            }
            else {
                result[i][0] = toupper(result[i][0]);
            }
            res+= result[i];
        }
        return res.substr(0,100);

    }
};
