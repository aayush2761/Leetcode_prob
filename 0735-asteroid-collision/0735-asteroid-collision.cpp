class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int i = 0;
        while (i < asteroids.size()) {
            if (!st.empty()) {
                int top = st.top();
                if (top > 0 && asteroids[i] < 0) {  
                    if (abs(top) < abs(asteroids[i])) {
                        st.pop();  
                        continue;  
                    } 
                    else if (abs(top) == abs(asteroids[i])) {
                        st.pop();  
                        i++;  
                    } 
                    else {
                        i++;  
                    }
                } 
                else {
                    st.push(asteroids[i]);  
                    i++;
                }
            } 
            else {
                st.push(asteroids[i]);  
                i++;
            }
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());  
        return res;
    }
};
