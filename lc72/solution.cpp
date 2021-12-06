#include "solution.h"

using namespace std;

int Solution::minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    
    // 初始状态, 第一行和第一列minDistance为行值或列值.
    for (int i = 0; i <= word1.size(); i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= word2.size(); i++)
    {
        dp[0][i] = i;
    }

    // 状态转移方程
    // word1[i] == word2[j] dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + 1, dp[i][j - 1] + 1)
    // word1[i] != word2[j] dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
    for (int i = 1; i <= word1.size(); i++)
    {
        for (int j = 1; j <= word2.size(); j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = min(dp[i - 1][j - 1], 1 + min(dp[i - 1][j], dp[i][j - 1]));
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    return dp.back().back();
}
