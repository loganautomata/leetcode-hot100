#include "solution.h"

using namespace std;

string Solution::longestPalindrome(string s)
{
    string res(s.begin(), s.begin() + 1);
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

    // dp[i][j] = true (j >= i)
    // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = true;
        }
    }

    for (int j = 1; j < dp.size(); j++)
    {
        for (int i = 0; i < j; i++)
        {
            dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            if (dp[i][j])
            {
                int palindrome_length = j - i + 1;
                if (palindrome_length > res.size())
                    res = s.substr(i, palindrome_length);
            }
        }
    }

    return res;
}
