#include "solution.h"

using namespace std;

int Solution::coinChange(vector<int>& coins, int amount)
{
    // dp[i] = min(dp[i - conins[0]], ..., dp[i - coins[n]]) + 1
    vector<int> dp(amount + 1, 0);

    sort(coins.begin(), coins.end());

    for (int i = 1; i < dp.size(); i++)
    {
        int min = INT32_MAX;

        for (int j = 0; j < coins.size() && i - coins[j] >= 0; j++)
        {
            if (dp[i - coins[j]] < min && dp[i - coins[j]] != -1)
            {
                min = dp[i - coins[j]];
            }
        }

        dp[i] = min == INT32_MAX ? -1 : min + 1;
    }

    return dp.back();
}
