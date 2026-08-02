class Solution {
    private:
    vector<int> pre(vector<int> &arr){
          vector<int>ans;
          stack<int>s;
          int n = arr.size();
          for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()) ans.push_back(s.top());
            else{
                ans.push_back(-1);
            }
            s.push(i);
          }
          return ans;
    }

    vector<int> next(vector<int> &arr){
          vector<int>ans;
          stack<int>s;
          int n = arr.size();
          for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] > arr[i]){
                s.pop();
            }
            if(!s.empty()) ans.push_back(s.top());
            else{
                ans.push_back(n);
            }
            s.push(i);
          }
          reverse(ans.begin(), ans.end());
          return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        int total = 0;
        vector<int>pse = pre(arr);
        vector<int>nse = next(arr);
        for(int i=0;i<n;i++){
            int l = i - pse[i];
            int r = nse[i] - i;
            total = (total + (l*r*1LL*arr[i])%MOD)%MOD; 
        }
        return total;
    }
};