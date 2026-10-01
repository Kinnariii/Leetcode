class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char a : s) {

            // Opening bracket
            if (a == '(' || a == '{' || a == '[') {
                st.push(a);
            }

            // Closing bracket
            else if (a == ')' || a == '}' || a == ']') {

                if (st.empty()) {
                    return false;
                }

                if ((a == ')' && st.top() == '(') ||
                    (a == ']' && st.top() == '[') ||
                    (a == '}' && st.top() == '{')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};