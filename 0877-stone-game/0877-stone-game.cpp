class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int i=0,j=piles.size()-1,al=0,bob=0;
        bool flag = true;
        while(i<j){
            if(flag){
            if(piles[i]>piles[j]){
                al += piles[i];
                i++;
            }
            else{
                al += piles[j];
                j--;
            }
            flag = !flag;
        }
        else{
            if(piles[i] > piles[j]){
                bob += piles[j];
                j--;
            }
            else{
                bob += piles[i];
                i++;
            }
            flag = !flag;
        }
        }
        if(al > bob) return true;
        return false;
    }
};