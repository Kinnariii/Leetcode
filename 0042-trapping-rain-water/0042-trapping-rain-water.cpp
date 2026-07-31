class Solution {
    vector<int>pre,suf;
    private:
    void prefix(vector<int> &pre,vector<int>& height){
        int n = height.size();
        pre.resize(n);
        pre[0] = height[0];
        for(int i=1;i<n;i++){
            pre[i] = max(pre[i-1],height[i]);
        }
        return;
    }
     void suffix(vector<int> &suf,vector<int>& height){
        int n = height.size();
        suf.resize(n);
        suf[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = max(suf[i+1],height[i]);
        }
        return;
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        prefix(pre,height);
        suffix(suf,height);
        int ans = 0;
        for(int i=0;i<n;i++){
            int lm = pre[i], rm = suf[i];
            ans += min(lm,rm) - height[i];
        }
        return ans;
    }
};