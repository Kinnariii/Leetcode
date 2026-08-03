class Solution {
    private:
    vector<int> nextsmaller(vector<int> &heights){
        stack<int>s;
        s.push(-1);
        int n = heights.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> previousmaller(vector<int> &heights){
        int n = heights.size();
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),maxi=INT_MIN;
        vector<int>nse = nextsmaller(heights);
        vector<int>pse = previousmaller(heights);
        for(int i=0;i<n;i++){
            int r = nse[i] == -1 ? n : nse[i];
            int ans = (r - pse[i] - 1)*heights[i];
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};