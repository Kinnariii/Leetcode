class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = LLONG_MIN, high = 0;

        for (int w : weights) {
            high += w;
            low = max(low, (long long)w);
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            int d = 1;
            int wt = 0;

            for (int w : weights) {
                if (wt + w > mid) {
                    d++;
                    wt = w;
                } else {
                    wt += w;
                }
            }

            if (d > days)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};