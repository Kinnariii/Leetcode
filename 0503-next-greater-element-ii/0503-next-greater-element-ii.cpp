class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n,-1);
        stack<int>s;
        for(int i=2*n - 1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i%n]){
                s.pop();
            }
            if(!s.empty() && (i<n)){
                arr[i] = s.top();
            }
            s.push(nums[i%n]);
        }
        return arr;
    }
};