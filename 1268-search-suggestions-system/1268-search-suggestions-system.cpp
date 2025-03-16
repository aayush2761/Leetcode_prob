// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//         //  at most three product names from products
//         // three lexicographically minimums products.    <--------- this is the real problem
//         int n = searchWord.size();
        
//     }
// };


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //  at most three product names from products
        int n = searchWord.size();
        sort(products.begin(),products.end());
        vector<vector<string>>res(n);
        for(int i=0;i<products.size();i++){
            int j=0;
            int index=0;
            int n1=products[i].size();
            while(index<n1 && j<n && products[i][index]==searchWord[j]){
                if(res[j].size()<3){
                    res[j].push_back(products[i]);
                }
                
                index++;
                j++;
            }
        }
        return res;
    }
};