class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char>s;
        for(int i=0;i<n;i++){
            while(k!=0 && !s.empty() && s.top() > num[i]){
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string ans = "";
        while(!s.empty()){
             ans += s.top();
             s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.length() && ans[i]=='0'){
            i++;
        }
        ans =  ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};