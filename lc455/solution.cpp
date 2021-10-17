#include "solution.h"

using namespace std;

int Solution::findContentChildren(vector<int> &g, vector<int> &s)
{
    int count = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    for (int i = 0, j = 0; i < g.size(); i++)
    {
        while (j < s.size())
        {
            if (s[j] >= g[i])
            {
                count++;
                j++;
                break;
            }
            else
                j++;
        }
        if (j == s.size())
            break;
    }

    return count;
}
