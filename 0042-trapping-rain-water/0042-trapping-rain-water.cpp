class Solution {
public:
    int trap(vector<int>& height) {
        int lm=-1,rm=-1,l=0,r=height.size()-1,total=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(lm > height[l]){
                    total += lm - height[l];
                }
                else{
                    lm = height[l];
                }
                l++;
            }
            else{
                if(rm > height[r]){
                    total += rm - height[r];
                }
                else{
                    rm = height[r];
                }
                r--;
            }
        }
        return total;
    }
};