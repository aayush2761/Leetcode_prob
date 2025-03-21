class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string>res;
        unordered_set<string>st;
        // for(auto it :recipes )st.insert(it);
        for(auto it :supplies )st.insert(it);
        bool flag1 = true;  // this current recipe added or not

    while(flag1){  
        flag1 = false; 

        for(int i = 0; i < recipes.size(); ++i){
            if(st.count(recipes[i]))continue;  

            bool flag2 = true;
            for(const string& ing : ingredients[i]){
                if (!st.count(ing)) { 
                    flag2 = false; break;
                }
            }

            if(flag2){  
                st.insert(recipes[i]); // further can used as supply
                res.push_back(recipes[i]);  
                flag1 = true;  
            }
        }
    }

    return res;
    }
};