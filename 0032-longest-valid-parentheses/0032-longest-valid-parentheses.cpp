class Solution {
public:
    int longestValidParentheses(string s) {
        int o=0,c=0,result = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                o++;
            }
            if(s[i] == ')'){
                c++;
            }
            if(o == c){
                result = max(result, o+c);
            }
            if(c > o){
                c=0;
                o=0;
            }
        }
        o=0;
        c=0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '(') o++;
            if(s[i] == ')') c++;
            if(o==c){
                result = max(result,o+c);
            }
            if(o > c){
                o=0;
                c=0;
            }
        }
        return result;
    }
};