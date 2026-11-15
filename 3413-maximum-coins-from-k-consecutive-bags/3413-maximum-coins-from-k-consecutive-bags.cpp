class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        int n = coins.size();

        auto fullCoins = [&](int i) -> long long {
            return 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        };

        long long ans = 0;

        // Case 1:
        // Window starts at the beginning of an interval.
        long long sum = 0;
        int right = 0;

        for (int left = 0; left < n; left++) {
            long long windowEnd = 1LL * coins[left][0] + k - 1;

            // Add intervals completely inside the window
            while (right < n && coins[right][1] <= windowEnd) {
                sum += fullCoins(right);
                right++;
            }

            // Add partially covered next interval
            if (right < n && coins[right][0] <= windowEnd) {
                long long coveredLength =
                    windowEnd - coins[right][0] + 1;

                ans = max(ans,
                          sum + coveredLength * coins[right][2]);
            } else {
                ans = max(ans, sum);
            }

            // Remove left interval before moving window
            sum -= fullCoins(left);
        }

        // Case 2:
        // Window ends at the end of an interval.
        sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += fullCoins(right);

            long long windowStart =
                1LL * coins[right][1] - k + 1;

            // Remove intervals completely before window
            while (coins[left][1] < windowStart) {
                sum -= fullCoins(left);
                left++;
            }

            // Remove uncovered part of the first interval
            long long uncovered =
                max(0LL, windowStart - coins[left][0]);

            ans = max(
                ans,
                sum - uncovered * coins[left][2]
            );
        }

        return ans;
    }
};