class Solution {
public:
    string answerString(string word, int numFriends) {
        int n= word.size();
        int t= numFriends;
        if(t==1) return word;
        int size= n-t+1;
        set<string>st;
        for(int i=0;i<n;i++){
             // Left substring ending at i
            int leftIndex = max(0, i - size + 1);
            string temp1 = word.substr(leftIndex, i - leftIndex + 1);

            // Right substring starting at i
            int rightIndex = min(n - 1, i + size - 1);
            string temp2 = word.substr(i, rightIndex - i + 1);
            
            st.insert(temp1);
            st.insert(temp2);

        }
        for(auto it = st.rbegin(); it!=st.rend();it++){
            string res=*it;
            return res;
            break;

        }
        return "";
    }
};