class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int>s;
        vector<int>ans;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums2[i] >= s.top()){
                s.pop();
            }
            if(s.empty()) mpp[nums2[i]] = -1;
            else{
                mpp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for(auto i : nums1){
            if(mpp.find(i) != mpp.end()){
                ans.push_back(mpp[i]);
            }
        }
        return ans;
    }
};