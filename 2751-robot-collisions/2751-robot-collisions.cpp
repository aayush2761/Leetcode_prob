class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // collides 
        // same health both removed 
        // different health less will be removed
        // bigger will be increased by 1
        vector<int> ans;
        stack<pair<pair<int, int>, char>> st;
        // positions, health, direction
        for(int i = 0; i < positions.size(); i++) {
            if(st.empty()) {
                st.push({{positions[i], healths[i]}, directions[i]});
            } else {
                if(st.top().second != directions[i]) {
                    if(st.top().first.second == healths[i]) {
                        st.pop();
                    } else if(st.top().first.second > healths[i]) {
                        st.top().first.second--;
                    } else if(st.top().first.second < healths[i]) {
                        st.pop();
                        st.push({{positions[i], healths[i]}, directions[i]});
                        st.top().first.second--;
                    }
                } else {
                    st.push({{positions[i], healths[i]}, directions[i]});
                }
            }
        }
        // fill the answer
        while(!st.empty()) {
            ans.push_back(st.top().first.second);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
