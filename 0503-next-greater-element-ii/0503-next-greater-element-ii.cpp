class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>s;
        vector<int>ans(2*n);
        for(int i=2*n-1;i>=0;i--){
            int e = nums[i%n];
            if(!s.empty() && s.top() > e){
                ans[i] = s.top();
            }
            else{
                while(!s.empty() && s.top()<= e){
                    s.pop();
                }
                if(s.empty()) ans[i] = -1;
                else{
                    ans[i] = s.top();
                }
            }
            s.push(e);
        }
        vector<int>final;
        for(int i=0;i<n;i++){
            final.push_back(ans[i]);
        }
        return final;
    }
};