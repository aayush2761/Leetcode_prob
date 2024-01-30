class Solution {
public:
    int evaluateExpression(char op, int a, int b) {
        if (op == '+')
            return a + b;
        else if (op == '-')
            return a - b;
        else if (op == '*')
            return a * b;
        else if (op == '/')
            return a / b;
        return 0; 
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(evaluateExpression(tokens[i][0], a, b));
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
