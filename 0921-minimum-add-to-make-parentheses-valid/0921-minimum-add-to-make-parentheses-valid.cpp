class Solution {
public:
    int minAddToMakeValid(string s) {
       if(s.length()==0) return 0;
       int cnt =0;
       stack<char>st;
       for(auto c : s){
        if(c == '('){
            st.push(c);
        }
        else {
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                cnt++;
            }
        }
       }
       return (cnt + st.size());
    }
};