class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        for(auto i : nums){
            if(i > maxi) maxi = i;
        }
        int s = 1,e=maxi,ans=0;
        while(s<=e){
            int mid = s + (e-s)/2;
            int res = 0;
            for(auto it : nums){
                //res += ceil(it/mid); // dont use this method
                // or use  sum=sum+ceil(double(nums[j])/double(mid));
                res += (it + mid - 1)/mid;
            }
            if(res <= threshold){
                e = mid-1;
            }
            else{
              s = mid+1;
            }
        }
        return s;
    }
};