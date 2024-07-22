class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        // kya krun ab //!!!!
        vector<string>res;
        if(digits.size()==0) return {};
        string currrenCombination;
        int index=0;
        backTrackFunction(digits,index,mp,currrenCombination,res);
        return res;


    }
    void backTrackFunction(string digits, int index,unordered_map<int,string>&mp, string& currrenCombination,vector<string>&res ){
        // base case 
        // if we go out of bound index just return it by pushing in res srtering bruhhh..!!
        if(index==digits.size()){
             res.push_back(currrenCombination);
             return;
        }

        char digit=digits[index]-'0';
        string letters = mp[digit];
        // traverse that function 
        for(char i : letters){
            currrenCombination.push_back(i);
            backTrackFunction(digits,index+1,mp,currrenCombination,res);
            currrenCombination.pop_back();
        }
    }
};


// how it actually implements is the blinders brains brooohhh!!
        //                          f(a)
        //             /             |                    \
        //          f(ad)           f(ae)                 f(ae)
        //      /   |   \         /   |   \             /   |   \
        // f(adg) f(adh) f(adi) f(aeg) f(aeh) f(aei)  f(aeg) f(aeh) f(aei)
        