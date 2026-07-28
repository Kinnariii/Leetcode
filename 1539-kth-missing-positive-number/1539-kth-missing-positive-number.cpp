class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1,n=arr.size(),cnt=0,i=0;
       while(i<n){
            int e = arr[i];
            if(num == e){
                num++;
                i++;
            }
            else{
                cnt++;
                if(cnt==k) return num;
                num++;
            }
        }
        while(cnt!=k){
            num++;
            cnt++;
        }
        return num - 1;
        
    }
};