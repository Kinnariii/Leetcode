class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int>mpp;
        int n = nums1.size(), m = nums2.size();
        for(int i = m - 1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            mpp[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
            
        }
        vector<int>ans;
        for(auto i : nums1){
            ans.push_back(mpp[i]);
        }
        return ans;
    }
};