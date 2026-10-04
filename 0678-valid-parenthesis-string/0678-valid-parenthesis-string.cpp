class Solution {
public:
    bool checkValidString(string s) {
        int lmax =0,lmin=0;
        for(char c : s){
            if(c == '('){
                lmax++;
                lmin++;
            }
            else if(c == ')'){
                lmax--;
                lmin--;
            }
            else{
                lmax++;
                lmin--;
            }
            if(lmax < 0){
                return false;
            }
            lmin = max(lmin,0);
        }
        return lmin == 0;
    }
};