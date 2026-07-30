class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n = nums.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            while(s.empty() == false && s.top() <= nums[i]){
                s.pop();
            }
            s.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(s.empty()==false && s.top() <= nums[i]){
                s.pop();
            }
            if(s.empty()) {
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            } 
            s.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};