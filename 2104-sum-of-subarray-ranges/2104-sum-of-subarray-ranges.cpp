class Solution {
private:

    // Next Smaller Element
    vector<int> NSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        return ans;
    }

    // Previous Smaller Element
    vector<int> PSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        for (int i = 0; i < n; i++) {

            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        return ans;
    }

    // Next Greater Element
    vector<int> NGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        return ans;
    }

    // Previous Greater Element
    vector<int> PGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        for (int i = 0; i < n; i++) {

            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        return ans;
    }

public:

    long long subArrayRanges(vector<int>& nums) {

        auto nse = NSE(nums);
        auto pse = PSE(nums);
        auto nge = NGE(nums);
        auto pge = PGE(nums);

        int n = nums.size();

        long long total = 0;

        for (int i = 0; i < n; i++) {

            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;

            long long mini = leftMin * rightMin;
            long long maxi = leftMax * rightMax;

            total += (maxi - mini) * nums[i];
        }

        return total;
    }
};