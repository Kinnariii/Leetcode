class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();
        if(n==1) return false;
        if(n==0) return true;
        int i = 0;
        while(i<n){
            if(s[i] == '(' || s[i] == '{' || s[i]=='['){
                st.push(s[i]);
                i++;
            }
            else{
                if(st.empty()) return false;
                if(st.top() == '(' && s[i] == ')' || st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']'){
                    st.pop();
                    i++;
                }
                else{
                    return false;
                }
            }
        }
       if(st.empty()) return true;
       return false;
    }
};