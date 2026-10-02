class Solution {
    private:
    void para(int n,vector<string> &ans,stack<char>st,int o,int c ){
        if(o==c && c==n){
            string temp = "";
            stack<char>st2;
            while(!st.empty()){
                st2.push(st.top());
                st.pop();
            }
            while(!st2.empty()){
                temp += st2.top();
                st2.pop();
            }
            ans.push_back(temp);
            return;
        }
        if(o > c){
            st.push(')');
            para(n,ans,st,o,c+1);
            st.pop();
        }
        if(o < n){
            st.push('(');
            para(n,ans,st,o+1,c);
            st.pop();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        if(n==1) return {"()"};
         vector<string>ans;
         stack<char>st;
         int o=0,c=0;
         para(n,ans,st,o,c);
         return ans;
    }
};