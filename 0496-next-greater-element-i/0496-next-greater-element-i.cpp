class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        int n = nums2.size();
        for(int i=0;i<n;i++){
            mpp[nums2[i]] = i;
        }
        stack<int>s;
        vector<int>ans(n);
        s.push(nums2[n-1]);
        ans[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            if(s.top() > nums2[i]){
                ans[i] = s.top();
            }
            else{
                while(!s.empty() && s.top()<= nums2[i]){
                    s.pop();
                }
                if(s.empty()) ans[i] = -1;
                else{
                    ans[i] = s.top();
                }
            }
            s.push(nums2[i]);
        }
        vector<int>final;
       for (int i = 0; i < nums1.size(); i++) {
            final.push_back(ans[mpp[nums1[i]]]);
        }
        return final;
    }
};