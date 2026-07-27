class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int res = -1;

        while (mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;

            int bouquets = 0;
            int cnt = 0;

            for (int day : bloomDay) {
                if (day <= mid) {
                    cnt++;                  // flower has bloomed
                } else {
                    bouquets += cnt / k;    // end of consecutive segment
                    cnt = 0;
                }
            }

            bouquets += cnt / k;            // last segment

            if (bouquets >= m) {
                res = mid;
                maxi = mid - 1;
            } else {
                mini = mid + 1;
            }
        }

        return res;
    }
};