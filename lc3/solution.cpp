#include "solution.h"

using namespace std;

int Solution::lengthOfLongestSubstring(string s)
{
    unordered_set<char> chs;
    int res = 0;

    for (pair<int, int> range(0, 0); range.second < s.size(); range.second++)
    {
        if (chs.find(s[range.second]) == chs.end())
        {
            chs.insert(s[range.second]);
        }
        else
        {
            while (range.first <= range.second)
            {
                if (s[range.first] == s[range.second])
                {
                    range.first++;
                    break;
                }
                else
                {
                    chs.erase(s[range.first]);
                    range.first++;
                }
            }
        }

        if (range.second - range.first + 1 > res)
        {
            res = range.second - range.first + 1;
        }
    }

    return res;
}
